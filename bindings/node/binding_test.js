const assert = require("node:assert");
const { test } = require("node:test");

const Parser = require("tree-sitter");

function parse(source) {
  const parser = new Parser();
  parser.setLanguage(require("."));
  return parser.parse(source);
}

test("can load grammar", () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(require(".")));
});

// #40: a token's span must not absorb whitespace skipped before it.
// `test/corpus` only checks tree *shape*, not byte offsets, so an
// off-by-N regression here would pass the corpus suite silently — these
// assert the actual numbers from the bug report and its `boneyard`
// counterpart (see src/scanner.c).
test("underline span excludes preceding whitespace (#40)", () => {
  const tree = parse("A dog      _wags_ its tail.");
  const [node] = tree.rootNode.descendantsOfType("underline");
  assert.strictEqual(node.text, "_wags_");
  assert.strictEqual(node.startIndex, 11);
  assert.strictEqual(node.endIndex, 17);
});

test("boneyard span excludes preceding whitespace (#40)", () => {
  const tree = parse("A dog      /* aside */ its tail.");
  const [node] = tree.rootNode.descendantsOfType("boneyard");
  assert.strictEqual(node.text, "/* aside */");
  assert.strictEqual(node.startIndex, 11);
  assert.strictEqual(node.endIndex, 22);
});

test("underline with no preceding whitespace is unaffected", () => {
  const tree = parse("word_notunderline_word");
  const [node] = tree.rootNode.descendantsOfType("underline");
  assert.strictEqual(node.text, "_notunderline_");
  assert.strictEqual(node.startIndex, 4);
});

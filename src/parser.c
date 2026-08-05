#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 110
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 5
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 22

enum ts_symbol_identifiers {
  sym_note = 1,
  sym_boneyard = 2,
  sym__scene_prefix = 3,
  sym__scene_word = 4,
  sym__scene_number = 5,
  anon_sym_DASH = 6,
  sym__scene_eol = 7,
  sym__forced_scene_line = 8,
  sym__transition_line = 9,
  sym__forced_transition_line = 10,
  sym__centered_line = 11,
  sym__character_line = 12,
  sym__forced_character_line = 13,
  sym__parenthetical_line = 14,
  sym__lyric_line = 15,
  sym__synopsis_line = 16,
  sym__section_marker = 17,
  sym__page_break_line = 18,
  sym__forced_action_line = 19,
  sym__title_key = 20,
  sym__any_line = 21,
  sym__blank = 22,
  sym_screenplay = 23,
  sym__block = 24,
  sym_title_page = 25,
  sym_title_entry = 26,
  sym_dialogue = 27,
  sym_character = 28,
  sym_parenthetical = 29,
  sym_lyric = 30,
  sym_scene_heading = 31,
  sym_location = 32,
  sym_time = 33,
  sym_transition = 34,
  sym_centered = 35,
  sym_synopsis = 36,
  sym_section = 37,
  sym_page_break = 38,
  sym_action = 39,
  sym__scene_start_line = 40,
  sym__scene_dash = 41,
  aux_sym_screenplay_repeat1 = 42,
  aux_sym_screenplay_repeat2 = 43,
  aux_sym_title_page_repeat1 = 44,
  aux_sym_title_entry_repeat1 = 45,
  aux_sym_dialogue_repeat1 = 46,
  aux_sym_lyric_repeat1 = 47,
  aux_sym_location_repeat1 = 48,
  aux_sym_location_repeat2 = 49,
  aux_sym_centered_repeat1 = 50,
  aux_sym_action_repeat1 = 51,
  aux_sym__scene_start_line_repeat1 = 52,
  alias_sym_dialogue_line = 53,
  alias_sym_scene_number = 54,
  alias_sym_scene_prefix = 55,
  alias_sym_section_title = 56,
  alias_sym_title_value = 57,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_note] = "note",
  [sym_boneyard] = "boneyard",
  [sym__scene_prefix] = "_scene_prefix",
  [sym__scene_word] = "_scene_word",
  [sym__scene_number] = "_scene_number",
  [anon_sym_DASH] = "-",
  [sym__scene_eol] = "_scene_eol",
  [sym__forced_scene_line] = "_forced_scene_line",
  [sym__transition_line] = "_transition_line",
  [sym__forced_transition_line] = "_forced_transition_line",
  [sym__centered_line] = "_centered_line",
  [sym__character_line] = "_character_line",
  [sym__forced_character_line] = "_forced_character_line",
  [sym__parenthetical_line] = "_parenthetical_line",
  [sym__lyric_line] = "_lyric_line",
  [sym__synopsis_line] = "_synopsis_line",
  [sym__section_marker] = "section_marker",
  [sym__page_break_line] = "_page_break_line",
  [sym__forced_action_line] = "_forced_action_line",
  [sym__title_key] = "title_key",
  [sym__any_line] = "_any_line",
  [sym__blank] = "_blank",
  [sym_screenplay] = "screenplay",
  [sym__block] = "_block",
  [sym_title_page] = "title_page",
  [sym_title_entry] = "title_entry",
  [sym_dialogue] = "dialogue",
  [sym_character] = "character",
  [sym_parenthetical] = "parenthetical",
  [sym_lyric] = "lyric",
  [sym_scene_heading] = "scene_heading",
  [sym_location] = "location",
  [sym_time] = "time",
  [sym_transition] = "transition",
  [sym_centered] = "centered",
  [sym_synopsis] = "synopsis",
  [sym_section] = "section",
  [sym_page_break] = "page_break",
  [sym_action] = "action",
  [sym__scene_start_line] = "_scene_start_line",
  [sym__scene_dash] = "_scene_dash",
  [aux_sym_screenplay_repeat1] = "screenplay_repeat1",
  [aux_sym_screenplay_repeat2] = "screenplay_repeat2",
  [aux_sym_title_page_repeat1] = "title_page_repeat1",
  [aux_sym_title_entry_repeat1] = "title_entry_repeat1",
  [aux_sym_dialogue_repeat1] = "dialogue_repeat1",
  [aux_sym_lyric_repeat1] = "lyric_repeat1",
  [aux_sym_location_repeat1] = "location_repeat1",
  [aux_sym_location_repeat2] = "location_repeat2",
  [aux_sym_centered_repeat1] = "centered_repeat1",
  [aux_sym_action_repeat1] = "action_repeat1",
  [aux_sym__scene_start_line_repeat1] = "_scene_start_line_repeat1",
  [alias_sym_dialogue_line] = "dialogue_line",
  [alias_sym_scene_number] = "scene_number",
  [alias_sym_scene_prefix] = "scene_prefix",
  [alias_sym_section_title] = "section_title",
  [alias_sym_title_value] = "title_value",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_note] = sym_note,
  [sym_boneyard] = sym_boneyard,
  [sym__scene_prefix] = sym__scene_prefix,
  [sym__scene_word] = sym__scene_word,
  [sym__scene_number] = sym__scene_number,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym__scene_eol] = sym__scene_eol,
  [sym__forced_scene_line] = sym__forced_scene_line,
  [sym__transition_line] = sym__transition_line,
  [sym__forced_transition_line] = sym__forced_transition_line,
  [sym__centered_line] = sym__centered_line,
  [sym__character_line] = sym__character_line,
  [sym__forced_character_line] = sym__forced_character_line,
  [sym__parenthetical_line] = sym__parenthetical_line,
  [sym__lyric_line] = sym__lyric_line,
  [sym__synopsis_line] = sym__synopsis_line,
  [sym__section_marker] = sym__section_marker,
  [sym__page_break_line] = sym__page_break_line,
  [sym__forced_action_line] = sym__forced_action_line,
  [sym__title_key] = sym__title_key,
  [sym__any_line] = sym__any_line,
  [sym__blank] = sym__blank,
  [sym_screenplay] = sym_screenplay,
  [sym__block] = sym__block,
  [sym_title_page] = sym_title_page,
  [sym_title_entry] = sym_title_entry,
  [sym_dialogue] = sym_dialogue,
  [sym_character] = sym_character,
  [sym_parenthetical] = sym_parenthetical,
  [sym_lyric] = sym_lyric,
  [sym_scene_heading] = sym_scene_heading,
  [sym_location] = sym_location,
  [sym_time] = sym_time,
  [sym_transition] = sym_transition,
  [sym_centered] = sym_centered,
  [sym_synopsis] = sym_synopsis,
  [sym_section] = sym_section,
  [sym_page_break] = sym_page_break,
  [sym_action] = sym_action,
  [sym__scene_start_line] = sym__scene_start_line,
  [sym__scene_dash] = sym__scene_dash,
  [aux_sym_screenplay_repeat1] = aux_sym_screenplay_repeat1,
  [aux_sym_screenplay_repeat2] = aux_sym_screenplay_repeat2,
  [aux_sym_title_page_repeat1] = aux_sym_title_page_repeat1,
  [aux_sym_title_entry_repeat1] = aux_sym_title_entry_repeat1,
  [aux_sym_dialogue_repeat1] = aux_sym_dialogue_repeat1,
  [aux_sym_lyric_repeat1] = aux_sym_lyric_repeat1,
  [aux_sym_location_repeat1] = aux_sym_location_repeat1,
  [aux_sym_location_repeat2] = aux_sym_location_repeat2,
  [aux_sym_centered_repeat1] = aux_sym_centered_repeat1,
  [aux_sym_action_repeat1] = aux_sym_action_repeat1,
  [aux_sym__scene_start_line_repeat1] = aux_sym__scene_start_line_repeat1,
  [alias_sym_dialogue_line] = alias_sym_dialogue_line,
  [alias_sym_scene_number] = alias_sym_scene_number,
  [alias_sym_scene_prefix] = alias_sym_scene_prefix,
  [alias_sym_section_title] = alias_sym_section_title,
  [alias_sym_title_value] = alias_sym_title_value,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_note] = {
    .visible = true,
    .named = true,
  },
  [sym_boneyard] = {
    .visible = true,
    .named = true,
  },
  [sym__scene_prefix] = {
    .visible = false,
    .named = true,
  },
  [sym__scene_word] = {
    .visible = false,
    .named = true,
  },
  [sym__scene_number] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym__scene_eol] = {
    .visible = false,
    .named = true,
  },
  [sym__forced_scene_line] = {
    .visible = false,
    .named = true,
  },
  [sym__transition_line] = {
    .visible = false,
    .named = true,
  },
  [sym__forced_transition_line] = {
    .visible = false,
    .named = true,
  },
  [sym__centered_line] = {
    .visible = false,
    .named = true,
  },
  [sym__character_line] = {
    .visible = false,
    .named = true,
  },
  [sym__forced_character_line] = {
    .visible = false,
    .named = true,
  },
  [sym__parenthetical_line] = {
    .visible = false,
    .named = true,
  },
  [sym__lyric_line] = {
    .visible = false,
    .named = true,
  },
  [sym__synopsis_line] = {
    .visible = false,
    .named = true,
  },
  [sym__section_marker] = {
    .visible = true,
    .named = true,
  },
  [sym__page_break_line] = {
    .visible = false,
    .named = true,
  },
  [sym__forced_action_line] = {
    .visible = false,
    .named = true,
  },
  [sym__title_key] = {
    .visible = true,
    .named = true,
  },
  [sym__any_line] = {
    .visible = false,
    .named = true,
  },
  [sym__blank] = {
    .visible = false,
    .named = true,
  },
  [sym_screenplay] = {
    .visible = true,
    .named = true,
  },
  [sym__block] = {
    .visible = false,
    .named = true,
  },
  [sym_title_page] = {
    .visible = true,
    .named = true,
  },
  [sym_title_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_dialogue] = {
    .visible = true,
    .named = true,
  },
  [sym_character] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthetical] = {
    .visible = true,
    .named = true,
  },
  [sym_lyric] = {
    .visible = true,
    .named = true,
  },
  [sym_scene_heading] = {
    .visible = true,
    .named = true,
  },
  [sym_location] = {
    .visible = true,
    .named = true,
  },
  [sym_time] = {
    .visible = true,
    .named = true,
  },
  [sym_transition] = {
    .visible = true,
    .named = true,
  },
  [sym_centered] = {
    .visible = true,
    .named = true,
  },
  [sym_synopsis] = {
    .visible = true,
    .named = true,
  },
  [sym_section] = {
    .visible = true,
    .named = true,
  },
  [sym_page_break] = {
    .visible = true,
    .named = true,
  },
  [sym_action] = {
    .visible = true,
    .named = true,
  },
  [sym__scene_start_line] = {
    .visible = false,
    .named = true,
  },
  [sym__scene_dash] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_screenplay_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_screenplay_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_title_page_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_title_entry_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialogue_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_lyric_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_location_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_location_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_centered_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__scene_start_line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_dialogue_line] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_scene_number] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_scene_prefix] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_section_title] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_title_value] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_character = 1,
  field_key = 2,
  field_location = 3,
  field_marker = 4,
  field_number = 5,
  field_prefix = 6,
  field_time = 7,
  field_title = 8,
  field_value = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_character] = "character",
  [field_key] = "key",
  [field_location] = "location",
  [field_marker] = "marker",
  [field_number] = "number",
  [field_prefix] = "prefix",
  [field_time] = "time",
  [field_title] = "title",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 0, .length = 1},
  [6] = {.index = 6, .length = 2},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 1},
  [9] = {.index = 10, .length = 2},
  [11] = {.index = 12, .length = 1},
  [12] = {.index = 13, .length = 3},
  [13] = {.index = 4, .length = 2},
  [14] = {.index = 16, .length = 2},
  [15] = {.index = 18, .length = 2},
  [16] = {.index = 20, .length = 2},
  [17] = {.index = 22, .length = 2},
  [18] = {.index = 24, .length = 3},
  [19] = {.index = 27, .length = 3},
  [20] = {.index = 30, .length = 3},
  [21] = {.index = 33, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_prefix, 0},
  [1] =
    {field_marker, 0},
  [2] =
    {field_number, 1},
    {field_prefix, 0},
  [4] =
    {field_location, 1},
    {field_prefix, 0},
  [6] =
    {field_marker, 0},
    {field_title, 1},
  [8] =
    {field_value, 0},
  [9] =
    {field_key, 0},
  [10] =
    {field_key, 0},
    {field_value, 1, .inherited = true},
  [12] =
    {field_character, 0},
  [13] =
    {field_location, 1},
    {field_number, 2},
    {field_prefix, 0},
  [16] =
    {field_number, 2},
    {field_prefix, 0},
  [18] =
    {field_prefix, 0},
    {field_time, 2},
  [20] =
    {field_key, 0},
    {field_value, 2, .inherited = true},
  [22] =
    {field_value, 0, .inherited = true},
    {field_value, 1, .inherited = true},
  [24] =
    {field_location, 1},
    {field_number, 3},
    {field_prefix, 0},
  [27] =
    {field_location, 1},
    {field_prefix, 0},
    {field_time, 3},
  [30] =
    {field_number, 3},
    {field_prefix, 0},
    {field_time, 2},
  [33] =
    {field_location, 1},
    {field_number, 4},
    {field_prefix, 0},
    {field_time, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_scene_prefix,
  },
  [3] = {
    [0] = alias_sym_scene_prefix,
    [1] = alias_sym_scene_number,
  },
  [4] = {
    [0] = alias_sym_scene_prefix,
  },
  [5] = {
    [0] = alias_sym_scene_prefix,
    [1] = anon_sym_DASH,
  },
  [6] = {
    [1] = alias_sym_section_title,
  },
  [7] = {
    [0] = alias_sym_title_value,
  },
  [10] = {
    [0] = alias_sym_dialogue_line,
  },
  [12] = {
    [0] = alias_sym_scene_prefix,
    [2] = alias_sym_scene_number,
  },
  [13] = {
    [0] = alias_sym_scene_prefix,
    [2] = anon_sym_DASH,
  },
  [14] = {
    [0] = alias_sym_scene_prefix,
    [1] = anon_sym_DASH,
    [2] = alias_sym_scene_number,
  },
  [15] = {
    [0] = alias_sym_scene_prefix,
    [1] = anon_sym_DASH,
  },
  [18] = {
    [0] = alias_sym_scene_prefix,
    [2] = anon_sym_DASH,
    [3] = alias_sym_scene_number,
  },
  [19] = {
    [0] = alias_sym_scene_prefix,
    [2] = anon_sym_DASH,
  },
  [20] = {
    [0] = alias_sym_scene_prefix,
    [1] = anon_sym_DASH,
    [3] = alias_sym_scene_number,
  },
  [21] = {
    [0] = alias_sym_scene_prefix,
    [2] = anon_sym_DASH,
    [4] = alias_sym_scene_number,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym__scene_dash, 2,
    sym__scene_dash,
    anon_sym_DASH,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 18,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 20,
  [24] = 22,
  [25] = 21,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 29,
  [34] = 28,
  [35] = 30,
  [36] = 31,
  [37] = 27,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 32,
  [45] = 39,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 52,
  [57] = 48,
  [58] = 27,
  [59] = 51,
  [60] = 60,
  [61] = 61,
  [62] = 47,
  [63] = 50,
  [64] = 53,
  [65] = 65,
  [66] = 66,
  [67] = 55,
  [68] = 68,
  [69] = 50,
  [70] = 70,
  [71] = 54,
  [72] = 65,
  [73] = 73,
  [74] = 53,
  [75] = 60,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 83,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 27,
  [109] = 109,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '!', 99,
        '#', 95,
        '(', 166,
        '-', 60,
        '.', 293,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'A', 224,
        'C', 211,
        'D', 187,
        'E', 222,
        'I', 178,
        'N', 217,
        'R', 194,
        'S', 215,
        'T', 206,
        '[', 238,
        'a', 288,
        'c', 268,
        'd', 243,
        'e', 277,
        'i', 179,
        'n', 272,
        'r', 250,
        's', 270,
        't', 263,
        '~', 84,
        '\t', 164,
        ' ', 164,
      );
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(61);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 57,
        '-', 60,
        '/', 50,
        '[', 54,
        '\t', 2,
        ' ', 2,
      );
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 30,
        '-', 60,
        '/', 20,
        '[', 27,
        '\t', 3,
        ' ', 3,
      );
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(101);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == ')') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(17);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == ']') ADVANCE(29);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(81);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(301);
      if (lookahead == '*') ADVANCE(18);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(75);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(69);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(69);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(302);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(302);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '>') ADVANCE(23);
      if (lookahead == '[') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 14:
      ADVANCE_MAP(
        '\n', 302,
        '\r', 12,
        '/', 20,
        '>', 73,
        '[', 27,
        '~', 84,
        '\t', 14,
        ' ', 14,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(26);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(78);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(59);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == ')') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '*') ADVANCE(18);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == '*') ADVANCE(18);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == '*') ADVANCE(19);
      END_STATE();
    case 21:
      if (lookahead == '/') ADVANCE(50);
      if (lookahead == '[') ADVANCE(54);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(21);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '-') ADVANCE(58);
      END_STATE();
    case 22:
      if (lookahead == ':') ADVANCE(11);
      if (lookahead == 'T') ADVANCE(25);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(26);
      END_STATE();
    case 23:
      if (lookahead == '<') ADVANCE(77);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 24:
      if (lookahead == '<') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == 'O') ADVANCE(22);
      if (lookahead == 'T') ADVANCE(25);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(26);
      END_STATE();
    case 26:
      if (lookahead == 'T') ADVANCE(25);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == '[') ADVANCE(28);
      END_STATE();
    case 28:
      if (lookahead == ']') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 29:
      if (lookahead == ']') ADVANCE(43);
      END_STATE();
    case 30:
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 31:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\t', 102,
        '\n', 302,
        '\r', 12,
        ' ', 102,
        '!', 99,
        '#', 95,
        '.', 241,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'A', 148,
        'C', 136,
        'D', 112,
        'E', 146,
        'I', 106,
        'N', 141,
        'R', 119,
        'S', 139,
        'T', 131,
        '[', 238,
        'a', 288,
        'c', 268,
        'd', 243,
        'e', 277,
        'i', 179,
        'n', 272,
        'r', 250,
        's', 270,
        't', 263,
        '~', 84,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 32:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\t', 103,
        '\n', 302,
        '\r', 12,
        ' ', 103,
        '!', 99,
        '#', 95,
        '.', 241,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'E', 146,
        'I', 106,
        '[', 238,
        'e', 277,
        'i', 179,
        '~', 84,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 33:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 57,
        '-', 60,
        '/', 50,
        '>', 58,
        '[', 54,
        '\t', 165,
        ' ', 165,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(53);
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 34:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 57,
        '-', 60,
        '/', 50,
        '[', 54,
        '\t', 2,
        ' ', 2,
      );
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 35:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 30,
        '-', 60,
        '/', 20,
        '[', 27,
        '\t', 3,
        ' ', 3,
      );
      END_STATE();
    case 36:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 302,
        '\r', 12,
        '(', 166,
        '/', 175,
        '>', 73,
        '[', 238,
        '~', 84,
        '\t', 172,
        ' ', 172,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 37:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 302,
        '\r', 12,
        '(', 166,
        '/', 175,
        '[', 238,
        '~', 84,
        '\t', 173,
        ' ', 173,
      );
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 38:
      if (eof) ADVANCE(42);
      if (lookahead == '\n') ADVANCE(302);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '/') ADVANCE(175);
      if (lookahead == '>') ADVANCE(73);
      if (lookahead == '[') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(176);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 39:
      if (eof) ADVANCE(42);
      if (lookahead == '\n') ADVANCE(302);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '/') ADVANCE(175);
      if (lookahead == '[') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(177);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 40:
      if (eof) ADVANCE(42);
      if (lookahead == '\n') ADVANCE(302);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == '>') ADVANCE(23);
      if (lookahead == '[') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 41:
      if (eof) ADVANCE(42);
      ADVANCE_MAP(
        '\n', 302,
        '\r', 12,
        '/', 20,
        '>', 73,
        '[', 27,
        '~', 84,
        '\t', 14,
        ' ', 14,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(26);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_boneyard);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__scene_prefix);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym__scene_prefix);
      if (lookahead == '/') ADVANCE(255);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '#') ADVANCE(59);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(48);
      if (lookahead == '/') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(49);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == ':') ADVANCE(58);
      if (lookahead == 'T') ADVANCE(52);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == 'O') ADVANCE(51);
      if (lookahead == 'T') ADVANCE(52);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == 'T') ADVANCE(52);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '[') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == ']') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == ']') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__scene_number);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__scene_eol);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__forced_scene_line);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\t') ADVANCE(66);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead == ' ') ADVANCE(63);
      if (lookahead == '(') ADVANCE(64);
      if (lookahead == '^') ADVANCE(66);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(63);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead == '(') ADVANCE(68);
      if (lookahead == ')') ADVANCE(65);
      if (lookahead != 0) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead == '(') ADVANCE(64);
      if (lookahead == '^') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(66);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(63);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\r') ADVANCE(68);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym__transition_line);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym__forced_transition_line);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(70);
      if (lookahead == '\r') ADVANCE(72);
      if (lookahead == '<') ADVANCE(76);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(71);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(70);
      if (lookahead == '\r') ADVANCE(72);
      if (lookahead == '<') ADVANCE(76);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(70);
      if (lookahead == '\r') ADVANCE(73);
      if (lookahead != 0) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(75);
      if (lookahead == '\r') ADVANCE(73);
      if (lookahead != 0) ADVANCE(73);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__centered_line);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(75);
      if (lookahead == '\r') ADVANCE(74);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(75);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym__character_line);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__forced_character_line);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__forced_character_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(80);
      if (lookahead != 0) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__parenthetical_line);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym__parenthetical_line);
      if (lookahead == '\n') ADVANCE(81);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym__lyric_line);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym__lyric_line);
      if (lookahead == '\n') ADVANCE(83);
      if (lookahead == '\r') ADVANCE(84);
      if (lookahead != 0) ADVANCE(84);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym__synopsis_line);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(85);
      if (lookahead == '\r') ADVANCE(88);
      if (lookahead == '=') ADVANCE(97);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(85);
      if (lookahead == '\r') ADVANCE(88);
      if (lookahead == '=') ADVANCE(86);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(85);
      if (lookahead == '\r') ADVANCE(88);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead == '\r') ADVANCE(88);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__section_marker);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(90);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(91);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(92);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(93);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(94);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__page_break_line);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym__page_break_line);
      if (lookahead == '\n') ADVANCE(96);
      if (lookahead == '\r') ADVANCE(89);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym__forced_action_line);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(98);
      if (lookahead == '\r') ADVANCE(99);
      if (lookahead != 0) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__title_key);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(100);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__any_line);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 102,
        '\n', 101,
        '\r', 4,
        ' ', 102,
        '!', 99,
        '#', 95,
        '.', 241,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'A', 148,
        'C', 136,
        'D', 112,
        'E', 146,
        'I', 106,
        'N', 141,
        'R', 119,
        'S', 139,
        'T', 131,
        '[', 238,
        'a', 288,
        'c', 268,
        'd', 243,
        'e', 277,
        'i', 179,
        'n', 272,
        'r', 250,
        's', 270,
        't', 263,
        '~', 84,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 103,
        '\n', 101,
        '\r', 4,
        ' ', 103,
        '!', 99,
        '#', 95,
        '.', 241,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'E', 146,
        'I', 106,
        '[', 238,
        'e', 277,
        'i', 179,
        '~', 84,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 45,
        '(', 174,
        '.', 45,
        'O', 107,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 45,
        '(', 174,
        '.', 46,
        '/', 255,
        'O', 107,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        '/', 252,
        'N', 156,
        'T', 137,
        '^', 300,
        'n', 281,
        '\'', 162,
        '-', 162,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        ':', 298,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        ':', 100,
        'O', 107,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        ':', 100,
        'S', 110,
        'T', 137,
        '^', 300,
        's', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        ':', 100,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'A', 124,
        'T', 137,
        '^', 300,
        'a', 256,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'A', 154,
        'R', 111,
        'T', 137,
        '^', 300,
        'a', 286,
        'r', 242,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'A', 154,
        'T', 137,
        '^', 300,
        'a', 286,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'A', 116,
        'O', 107,
        'T', 137,
        '^', 300,
        'a', 247,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'C', 123,
        'T', 137,
        '^', 300,
        'c', 253,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'C', 159,
        'T', 137,
        '^', 300,
        'c', 283,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'D', 113,
        'T', 137,
        '^', 300,
        'd', 244,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'D', 132,
        'T', 137,
        '^', 300,
        'd', 264,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'E', 150,
        'T', 137,
        '^', 300,
        'e', 290,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'E', 118,
        'T', 137,
        '^', 300,
        'e', 249,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'E', 145,
        'O', 107,
        'T', 137,
        '^', 300,
        'e', 276,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'E', 110,
        'O', 107,
        'T', 137,
        '^', 300,
        'e', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'E', 110,
        'T', 137,
        '^', 300,
        'e', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'F', 160,
        'T', 137,
        '^', 300,
        'f', 284,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'G', 127,
        'T', 137,
        '^', 300,
        'g', 259,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'H', 140,
        'O', 107,
        'T', 137,
        '^', 300,
        'h', 271,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'H', 159,
        'T', 137,
        '^', 300,
        'h', 283,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'I', 125,
        'T', 137,
        '^', 300,
        'i', 257,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'I', 147,
        'T', 137,
        '^', 300,
        'i', 278,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'I', 138,
        'T', 137,
        '^', 300,
        'i', 269,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'I', 157,
        'T', 137,
        '^', 300,
        'i', 282,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'I', 159,
        'T', 137,
        '^', 300,
        'i', 283,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'L', 123,
        'O', 107,
        'T', 137,
        '^', 300,
        'l', 253,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'N', 110,
        'T', 137,
        '^', 300,
        'n', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'N', 158,
        'P', 151,
        'T', 137,
        '^', 300,
        'n', 285,
        'p', 292,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 135,
        'R', 120,
        'T', 137,
        '^', 300,
        'o', 267,
        'r', 251,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 107,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 134,
        'T', 137,
        '^', 300,
        'o', 266,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 149,
        'T', 137,
        '^', 300,
        'o', 289,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 143,
        'T', 137,
        '^', 300,
        'o', 274,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'O', 161,
        'T', 137,
        '^', 300,
        'o', 287,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'R', 115,
        'T', 137,
        '^', 300,
        'r', 246,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'R', 109,
        'T', 137,
        '^', 300,
        'r', 184,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'R', 128,
        'T', 137,
        '^', 300,
        'r', 260,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'S', 110,
        'T', 137,
        '^', 300,
        's', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'S', 155,
        'T', 137,
        'X', 155,
        '^', 300,
        's', 280,
        'x', 280,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'S', 130,
        'T', 137,
        '^', 300,
        's', 262,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 137,
        'U', 153,
        '^', 300,
        'u', 279,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 137,
        'U', 142,
        '^', 300,
        'u', 273,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 137,
        'V', 129,
        '^', 300,
        'v', 261,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 137,
        'Y', 144,
        '^', 300,
        'y', 275,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 126,
        '^', 300,
        't', 258,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 122,
        '^', 300,
        't', 253,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 104,
        '^', 300,
        't', 240,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 105,
        '^', 300,
        't', 169,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 133,
        '^', 300,
        't', 265,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 114,
        '^', 300,
        't', 245,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 108,
        '^', 300,
        't', 185,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 163,
        '^', 300,
        't', 171,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 152,
        '(', 174,
        'T', 121,
        '^', 300,
        't', 254,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\t') ADVANCE(300);
      if (lookahead == '\n') ADVANCE(78);
      if (lookahead == '\r') ADVANCE(15);
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == '(') ADVANCE(174);
      if (lookahead == '^') ADVANCE(300);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(162);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(162);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 300,
        '\n', 78,
        '\r', 15,
        ' ', 117,
        '(', 174,
        'O', 107,
        'T', 137,
        '^', 300,
        '\'', 162,
        '-', 162,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(152);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '!', 99,
        '#', 95,
        '(', 166,
        '-', 60,
        '.', 293,
        '/', 175,
        '=', 87,
        '>', 71,
        '@', 80,
        'A', 224,
        'C', 211,
        'D', 187,
        'E', 222,
        'I', 178,
        'N', 217,
        'R', 194,
        'S', 215,
        'T', 206,
        '[', 238,
        'a', 288,
        'c', 268,
        'd', 243,
        'e', 277,
        'i', 179,
        'n', 272,
        'r', 250,
        's', 270,
        't', 263,
        '~', 84,
        '\t', 164,
        ' ', 164,
      );
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 61,
        '\r', 1,
        '#', 57,
        '-', 60,
        '/', 50,
        '>', 58,
        '[', 54,
        '\t', 165,
        ' ', 165,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(53);
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '(') ADVANCE(295);
      if (lookahead == ')') ADVANCE(82);
      if (lookahead != 0) ADVANCE(166);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == ']') ADVANCE(239);
      if (lookahead != 0) ADVANCE(167);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead == '.') ADVANCE(46);
      if (lookahead == '/') ADVANCE(255);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(45);
      if (lookahead == '.') ADVANCE(46);
      if (lookahead == '/') ADVANCE(255);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(192);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(248);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 101,
        '\r', 4,
        '(', 166,
        '/', 175,
        '>', 73,
        '[', 238,
        '~', 84,
        '\t', 172,
        ' ', 172,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 101,
        '\r', 4,
        '(', 166,
        '/', 175,
        '[', 238,
        '~', 84,
        '\t', 173,
        ' ', 173,
      );
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '(') ADVANCE(295);
      if (lookahead == ')') ADVANCE(299);
      if (lookahead != 0) ADVANCE(174);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '*') ADVANCE(297);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(175);
      if (lookahead == '>') ADVANCE(73);
      if (lookahead == '[') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(176);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(175);
      if (lookahead == '[') ADVANCE(238);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(177);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == 'N') ADVANCE(232);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'n') ADVANCE(281);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(252);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(281);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(298);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(100);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(100);
      if (lookahead == 'S') ADVANCE(183);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 's') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(100);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(100);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(185);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(100);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A') ADVANCE(199);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'a') ADVANCE(256);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A') ADVANCE(230);
      if (lookahead == 'R') ADVANCE(186);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'a') ADVANCE(286);
      if (lookahead == 'r') ADVANCE(242);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A') ADVANCE(230);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'a') ADVANCE(286);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A') ADVANCE(191);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'a') ADVANCE(247);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C') ADVANCE(198);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'c') ADVANCE(253);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C') ADVANCE(236);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'c') ADVANCE(283);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(188);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'd') ADVANCE(244);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D') ADVANCE(207);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'd') ADVANCE(264);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(226);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(290);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(193);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(249);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(221);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(276);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(183);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E') ADVANCE(183);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'F') ADVANCE(235);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'f') ADVANCE(284);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'G') ADVANCE(202);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'g') ADVANCE(259);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H') ADVANCE(216);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'h') ADVANCE(271);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H') ADVANCE(236);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'h') ADVANCE(283);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I') ADVANCE(200);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(257);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I') ADVANCE(223);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(278);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I') ADVANCE(214);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(269);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I') ADVANCE(233);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(282);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I') ADVANCE(236);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(283);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'L') ADVANCE(198);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'l') ADVANCE(253);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N') ADVANCE(183);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'n') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N') ADVANCE(234);
      if (lookahead == 'P') ADVANCE(227);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'n') ADVANCE(285);
      if (lookahead == 'p') ADVANCE(292);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(210);
      if (lookahead == 'R') ADVANCE(195);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'o') ADVANCE(267);
      if (lookahead == 'r') ADVANCE(251);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(180);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(209);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'o') ADVANCE(266);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(225);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'o') ADVANCE(289);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(219);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'o') ADVANCE(274);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(237);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'o') ADVANCE(287);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R') ADVANCE(190);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'r') ADVANCE(246);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R') ADVANCE(182);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'r') ADVANCE(184);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R') ADVANCE(203);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'r') ADVANCE(260);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S') ADVANCE(183);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 's') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S') ADVANCE(231);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'X') ADVANCE(231);
      if (lookahead == 's') ADVANCE(280);
      if (lookahead == 'x') ADVANCE(280);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S') ADVANCE(205);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 's') ADVANCE(262);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'U') ADVANCE(229);
      if (lookahead == 'u') ADVANCE(279);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'U') ADVANCE(218);
      if (lookahead == 'u') ADVANCE(273);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'V') ADVANCE(204);
      if (lookahead == 'v') ADVANCE(261);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == 'Y') ADVANCE(220);
      if (lookahead == 'y') ADVANCE(275);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(213);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(201);
      if (lookahead == 't') ADVANCE(258);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(197);
      if (lookahead == 't') ADVANCE(253);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(212);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(168);
      if (lookahead == 't') ADVANCE(169);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(208);
      if (lookahead == 't') ADVANCE(265);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(189);
      if (lookahead == 't') ADVANCE(245);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(170);
      if (lookahead == 't') ADVANCE(171);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(181);
      if (lookahead == 't') ADVANCE(185);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(196);
      if (lookahead == 't') ADVANCE(254);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(228);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '[') ADVANCE(167);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ']') ADVANCE(43);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(45);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(294);
      if (('\t' <= lookahead && lookahead <= '\f')) ADVANCE(295);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(63);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(256);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(286);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(242);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(286);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(247);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(253);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(283);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(244);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(264);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(290);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(249);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(240);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(185);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(276);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(291);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(284);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(259);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(271);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(283);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(257);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(278);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(269);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(282);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(283);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(253);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(185);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(285);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(292);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(267);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(251);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(266);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(289);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(274);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(287);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(246);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(184);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(260);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(185);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(280);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(280);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(262);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(258);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(240);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(169);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(265);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(185);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(171);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(245);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(253);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(254);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(279);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(273);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(261);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(280);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(275);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ' ||
          lookahead == '.') ADVANCE(295);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(294);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(162);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(101);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(301);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '*') ADVANCE(296);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead != 0) ADVANCE(297);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(301);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '*') ADVANCE(296);
      if (lookahead != 0) ADVANCE(297);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(69);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(298);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(78);
      if (lookahead == '\r') ADVANCE(15);
      if (lookahead == '(') ADVANCE(174);
      if (lookahead == '^') ADVANCE(300);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(299);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(78);
      if (lookahead == '\r') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(300);
      if (lookahead != 0) ADVANCE(295);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '*') ADVANCE(18);
      if (lookahead != 0) ADVANCE(19);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym__blank);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 31},
  [2] = {.lex_state = 32},
  [3] = {.lex_state = 32},
  [4] = {.lex_state = 32},
  [5] = {.lex_state = 32},
  [6] = {.lex_state = 32},
  [7] = {.lex_state = 32},
  [8] = {.lex_state = 32},
  [9] = {.lex_state = 31},
  [10] = {.lex_state = 31},
  [11] = {.lex_state = 31},
  [12] = {.lex_state = 31},
  [13] = {.lex_state = 31},
  [14] = {.lex_state = 31},
  [15] = {.lex_state = 32},
  [16] = {.lex_state = 32},
  [17] = {.lex_state = 31},
  [18] = {.lex_state = 33},
  [19] = {.lex_state = 33},
  [20] = {.lex_state = 33},
  [21] = {.lex_state = 33},
  [22] = {.lex_state = 33},
  [23] = {.lex_state = 33},
  [24] = {.lex_state = 33},
  [25] = {.lex_state = 33},
  [26] = {.lex_state = 34},
  [27] = {.lex_state = 33},
  [28] = {.lex_state = 37},
  [29] = {.lex_state = 33},
  [30] = {.lex_state = 33},
  [31] = {.lex_state = 37},
  [32] = {.lex_state = 36},
  [33] = {.lex_state = 33},
  [34] = {.lex_state = 37},
  [35] = {.lex_state = 33},
  [36] = {.lex_state = 37},
  [37] = {.lex_state = 33},
  [38] = {.lex_state = 34},
  [39] = {.lex_state = 37},
  [40] = {.lex_state = 35},
  [41] = {.lex_state = 34},
  [42] = {.lex_state = 35},
  [43] = {.lex_state = 34},
  [44] = {.lex_state = 36},
  [45] = {.lex_state = 37},
  [46] = {.lex_state = 34},
  [47] = {.lex_state = 38},
  [48] = {.lex_state = 38},
  [49] = {.lex_state = 35},
  [50] = {.lex_state = 37},
  [51] = {.lex_state = 38},
  [52] = {.lex_state = 38},
  [53] = {.lex_state = 37},
  [54] = {.lex_state = 37},
  [55] = {.lex_state = 38},
  [56] = {.lex_state = 38},
  [57] = {.lex_state = 38},
  [58] = {.lex_state = 34},
  [59] = {.lex_state = 38},
  [60] = {.lex_state = 38},
  [61] = {.lex_state = 41},
  [62] = {.lex_state = 38},
  [63] = {.lex_state = 37},
  [64] = {.lex_state = 37},
  [65] = {.lex_state = 37},
  [66] = {.lex_state = 40},
  [67] = {.lex_state = 38},
  [68] = {.lex_state = 35},
  [69] = {.lex_state = 41},
  [70] = {.lex_state = 40},
  [71] = {.lex_state = 37},
  [72] = {.lex_state = 37},
  [73] = {.lex_state = 35},
  [74] = {.lex_state = 41},
  [75] = {.lex_state = 38},
  [76] = {.lex_state = 35},
  [77] = {.lex_state = 37},
  [78] = {.lex_state = 39},
  [79] = {.lex_state = 41},
  [80] = {.lex_state = 41},
  [81] = {.lex_state = 35},
  [82] = {.lex_state = 35},
  [83] = {.lex_state = 39},
  [84] = {.lex_state = 41},
  [85] = {.lex_state = 35},
  [86] = {.lex_state = 41},
  [87] = {.lex_state = 35},
  [88] = {.lex_state = 41},
  [89] = {.lex_state = 41},
  [90] = {.lex_state = 41},
  [91] = {.lex_state = 41},
  [92] = {.lex_state = 41},
  [93] = {.lex_state = 41},
  [94] = {.lex_state = 41},
  [95] = {.lex_state = 21},
  [96] = {.lex_state = 41},
  [97] = {.lex_state = 41},
  [98] = {.lex_state = 41},
  [99] = {.lex_state = 41},
  [100] = {.lex_state = 41},
  [101] = {.lex_state = 41},
  [102] = {.lex_state = 41},
  [103] = {.lex_state = 39},
  [104] = {.lex_state = 41},
  [105] = {.lex_state = 41},
  [106] = {.lex_state = 41},
  [107] = {.lex_state = 41},
  [108] = {.lex_state = 21},
  [109] = {.lex_state = 35},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym__scene_eol] = ACTIONS(1),
    [sym__forced_scene_line] = ACTIONS(1),
    [sym__transition_line] = ACTIONS(1),
    [sym__forced_transition_line] = ACTIONS(1),
    [sym__centered_line] = ACTIONS(1),
    [sym__forced_character_line] = ACTIONS(1),
    [sym__parenthetical_line] = ACTIONS(1),
    [sym__lyric_line] = ACTIONS(1),
    [sym__synopsis_line] = ACTIONS(1),
    [sym__section_marker] = ACTIONS(1),
    [sym__page_break_line] = ACTIONS(1),
    [sym__forced_action_line] = ACTIONS(1),
    [sym__title_key] = ACTIONS(1),
    [sym__any_line] = ACTIONS(1),
    [sym__blank] = ACTIONS(1),
  },
  [1] = {
    [sym_screenplay] = STATE(109),
    [sym__block] = STATE(80),
    [sym_title_page] = STATE(2),
    [sym_title_entry] = STATE(10),
    [sym_dialogue] = STATE(80),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(80),
    [sym_scene_heading] = STATE(80),
    [sym_transition] = STATE(80),
    [sym_centered] = STATE(80),
    [sym_synopsis] = STATE(80),
    [sym_section] = STATE(80),
    [sym_page_break] = STATE(80),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat1] = STATE(3),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_title_page_repeat1] = STATE(10),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__title_key] = ACTIONS(31),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(33),
  },
  [2] = {
    [sym__block] = STATE(84),
    [sym_dialogue] = STATE(84),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(84),
    [sym_scene_heading] = STATE(84),
    [sym_transition] = STATE(84),
    [sym_centered] = STATE(84),
    [sym_synopsis] = STATE(84),
    [sym_section] = STATE(84),
    [sym_page_break] = STATE(84),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat1] = STATE(4),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(37),
  },
  [3] = {
    [sym__block] = STATE(84),
    [sym_dialogue] = STATE(84),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(84),
    [sym_scene_heading] = STATE(84),
    [sym_transition] = STATE(84),
    [sym_centered] = STATE(84),
    [sym_synopsis] = STATE(84),
    [sym_section] = STATE(84),
    [sym_page_break] = STATE(84),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat1] = STATE(16),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(39),
  },
  [4] = {
    [sym__block] = STATE(79),
    [sym_dialogue] = STATE(79),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(79),
    [sym_scene_heading] = STATE(79),
    [sym_transition] = STATE(79),
    [sym_centered] = STATE(79),
    [sym_synopsis] = STATE(79),
    [sym_section] = STATE(79),
    [sym_page_break] = STATE(79),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat1] = STATE(16),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(39),
  },
  [5] = {
    [sym__block] = STATE(79),
    [sym_dialogue] = STATE(79),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(79),
    [sym_scene_heading] = STATE(79),
    [sym_transition] = STATE(79),
    [sym_centered] = STATE(79),
    [sym_synopsis] = STATE(79),
    [sym_section] = STATE(79),
    [sym_page_break] = STATE(79),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
  },
  [6] = {
    [sym__block] = STATE(86),
    [sym_dialogue] = STATE(86),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(86),
    [sym_scene_heading] = STATE(86),
    [sym_transition] = STATE(86),
    [sym_centered] = STATE(86),
    [sym_synopsis] = STATE(86),
    [sym_section] = STATE(86),
    [sym_page_break] = STATE(86),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
  },
  [7] = {
    [sym__block] = STATE(84),
    [sym_dialogue] = STATE(84),
    [sym_character] = STATE(45),
    [sym_lyric] = STATE(84),
    [sym_scene_heading] = STATE(84),
    [sym_transition] = STATE(84),
    [sym_centered] = STATE(84),
    [sym_synopsis] = STATE(84),
    [sym_section] = STATE(84),
    [sym_page_break] = STATE(84),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(48),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(7),
    [sym__forced_scene_line] = ACTIONS(9),
    [sym__transition_line] = ACTIONS(11),
    [sym__forced_transition_line] = ACTIONS(13),
    [sym__centered_line] = ACTIONS(15),
    [sym__character_line] = ACTIONS(17),
    [sym__forced_character_line] = ACTIONS(19),
    [sym__lyric_line] = ACTIONS(21),
    [sym__synopsis_line] = ACTIONS(23),
    [sym__section_marker] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
  },
  [8] = {
    [sym__block] = STATE(104),
    [sym_dialogue] = STATE(104),
    [sym_character] = STATE(39),
    [sym_lyric] = STATE(104),
    [sym_scene_heading] = STATE(104),
    [sym_transition] = STATE(104),
    [sym_centered] = STATE(104),
    [sym_synopsis] = STATE(104),
    [sym_section] = STATE(104),
    [sym_page_break] = STATE(104),
    [sym_action] = STATE(61),
    [sym__scene_start_line] = STATE(57),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(47),
    [sym__forced_scene_line] = ACTIONS(50),
    [sym__transition_line] = ACTIONS(53),
    [sym__forced_transition_line] = ACTIONS(56),
    [sym__centered_line] = ACTIONS(59),
    [sym__character_line] = ACTIONS(62),
    [sym__forced_character_line] = ACTIONS(65),
    [sym__lyric_line] = ACTIONS(68),
    [sym__synopsis_line] = ACTIONS(71),
    [sym__section_marker] = ACTIONS(74),
    [sym__page_break_line] = ACTIONS(77),
    [sym__forced_action_line] = ACTIONS(80),
    [sym__any_line] = ACTIONS(80),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    ACTIONS(87), 1,
      sym__title_key,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(9), 2,
      sym_title_entry,
      aux_sym_title_page_repeat1,
    ACTIONS(85), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
      sym__blank,
  [31] = 5,
    ACTIONS(31), 1,
      sym__title_key,
    ACTIONS(90), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(9), 2,
      sym_title_entry,
      aux_sym_title_page_repeat1,
    ACTIONS(92), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
      sym__blank,
  [62] = 5,
    ACTIONS(94), 1,
      ts_builtin_sym_end,
    ACTIONS(98), 1,
      sym__any_line,
    STATE(14), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(96), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [92] = 5,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    STATE(13), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(102), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [122] = 5,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
    STATE(14), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(106), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [152] = 5,
    ACTIONS(108), 1,
      ts_builtin_sym_end,
    ACTIONS(112), 1,
      sym__any_line,
    STATE(14), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(110), 14,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [182] = 5,
    ACTIONS(39), 1,
      sym__blank,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(115), 13,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
  [211] = 5,
    ACTIONS(117), 1,
      ts_builtin_sym_end,
    ACTIONS(121), 1,
      sym__blank,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(119), 13,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
  [240] = 3,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(126), 15,
      sym__scene_prefix,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_marker,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__any_line,
      sym__blank,
  [265] = 12,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    ACTIONS(131), 1,
      sym__scene_word,
    ACTIONS(133), 1,
      sym__scene_number,
    ACTIONS(135), 1,
      anon_sym_DASH,
    ACTIONS(137), 1,
      sym__scene_eol,
    ACTIONS(141), 1,
      sym__blank,
    STATE(21), 1,
      sym__scene_dash,
    STATE(22), 1,
      aux_sym__scene_start_line_repeat1,
    STATE(26), 1,
      aux_sym_location_repeat1,
    STATE(49), 1,
      sym_location,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(139), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [305] = 11,
    ACTIONS(141), 1,
      sym__blank,
    ACTIONS(144), 1,
      sym__scene_word,
    ACTIONS(146), 1,
      sym__scene_number,
    ACTIONS(148), 1,
      anon_sym_DASH,
    ACTIONS(150), 1,
      sym__scene_eol,
    STATE(24), 1,
      aux_sym__scene_start_line_repeat1,
    STATE(25), 1,
      sym__scene_dash,
    STATE(26), 1,
      aux_sym_location_repeat1,
    STATE(49), 1,
      sym_location,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(139), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [342] = 6,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
    ACTIONS(157), 1,
      anon_sym_DASH,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(154), 2,
      sym__scene_word,
      sym__scene_number,
    STATE(20), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(160), 5,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [368] = 9,
    ACTIONS(162), 1,
      ts_builtin_sym_end,
    ACTIONS(165), 1,
      sym__scene_word,
    ACTIONS(168), 1,
      sym__scene_number,
    ACTIONS(173), 1,
      sym__scene_eol,
    ACTIONS(176), 1,
      sym__blank,
    STATE(46), 1,
      aux_sym_location_repeat1,
    STATE(68), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 4,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [400] = 7,
    ACTIONS(135), 1,
      anon_sym_DASH,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(183), 1,
      sym__scene_eol,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(181), 2,
      sym__scene_word,
      sym__scene_number,
    STATE(20), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(185), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [428] = 5,
    ACTIONS(190), 1,
      anon_sym_DASH,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(187), 2,
      sym__scene_word,
      sym__scene_number,
    STATE(23), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(160), 5,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [451] = 6,
    ACTIONS(148), 1,
      anon_sym_DASH,
    ACTIONS(195), 1,
      sym__scene_eol,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(193), 2,
      sym__scene_word,
      sym__scene_number,
    STATE(23), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(185), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [476] = 8,
    ACTIONS(165), 1,
      sym__scene_word,
    ACTIONS(168), 1,
      sym__scene_number,
    ACTIONS(173), 1,
      sym__scene_eol,
    ACTIONS(176), 1,
      sym__blank,
    STATE(46), 1,
      aux_sym_location_repeat1,
    STATE(68), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 4,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [505] = 8,
    ACTIONS(199), 1,
      sym__scene_word,
    ACTIONS(201), 1,
      anon_sym_DASH,
    ACTIONS(204), 1,
      sym__blank,
    STATE(41), 1,
      aux_sym_location_repeat1,
    STATE(42), 1,
      aux_sym_location_repeat2,
    STATE(95), 1,
      sym__scene_dash,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(197), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [533] = 3,
    ACTIONS(206), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(208), 8,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [551] = 8,
    ACTIONS(210), 1,
      ts_builtin_sym_end,
    ACTIONS(212), 1,
      sym__parenthetical_line,
    ACTIONS(214), 1,
      sym__lyric_line,
    ACTIONS(216), 1,
      sym__any_line,
    ACTIONS(218), 1,
      sym__blank,
    STATE(50), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(31), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [579] = 4,
    ACTIONS(220), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
    ACTIONS(223), 5,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__blank,
  [599] = 5,
    ACTIONS(226), 1,
      ts_builtin_sym_end,
    ACTIONS(229), 1,
      sym__scene_eol,
    ACTIONS(232), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 6,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [621] = 8,
    ACTIONS(235), 1,
      ts_builtin_sym_end,
    ACTIONS(237), 1,
      sym__parenthetical_line,
    ACTIONS(240), 1,
      sym__lyric_line,
    ACTIONS(243), 1,
      sym__any_line,
    ACTIONS(246), 1,
      sym__blank,
    STATE(50), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(31), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [649] = 6,
    ACTIONS(248), 1,
      ts_builtin_sym_end,
    ACTIONS(254), 1,
      sym__any_line,
    STATE(51), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(252), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(250), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [672] = 3,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
    ACTIONS(223), 5,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__blank,
  [689] = 7,
    ACTIONS(218), 1,
      sym__blank,
    ACTIONS(257), 1,
      sym__parenthetical_line,
    ACTIONS(259), 1,
      sym__lyric_line,
    ACTIONS(261), 1,
      sym__any_line,
    STATE(63), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(36), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [714] = 4,
    ACTIONS(229), 1,
      sym__scene_eol,
    ACTIONS(232), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(171), 6,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [733] = 7,
    ACTIONS(246), 1,
      sym__blank,
    ACTIONS(263), 1,
      sym__parenthetical_line,
    ACTIONS(266), 1,
      sym__lyric_line,
    ACTIONS(269), 1,
      sym__any_line,
    STATE(63), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(36), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [758] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(208), 8,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [773] = 8,
    ACTIONS(272), 1,
      ts_builtin_sym_end,
    ACTIONS(274), 1,
      sym__scene_word,
    ACTIONS(276), 1,
      sym__scene_number,
    ACTIONS(278), 1,
      sym__scene_eol,
    ACTIONS(280), 1,
      sym__blank,
    STATE(46), 1,
      aux_sym_location_repeat1,
    STATE(73), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [799] = 6,
    ACTIONS(257), 1,
      sym__parenthetical_line,
    ACTIONS(259), 1,
      sym__lyric_line,
    ACTIONS(261), 1,
      sym__any_line,
    STATE(63), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(34), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [821] = 6,
    ACTIONS(286), 1,
      anon_sym_DASH,
    ACTIONS(289), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat2,
    STATE(95), 1,
      sym__scene_dash,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(282), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [843] = 5,
    ACTIONS(293), 1,
      sym__scene_word,
    ACTIONS(296), 1,
      sym__blank,
    STATE(41), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(291), 4,
      ts_builtin_sym_end,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
  [863] = 6,
    ACTIONS(300), 1,
      anon_sym_DASH,
    ACTIONS(303), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat2,
    STATE(95), 1,
      sym__scene_dash,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(298), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [885] = 5,
    ACTIONS(199), 1,
      sym__scene_word,
    ACTIONS(289), 1,
      sym__blank,
    STATE(41), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(282), 4,
      ts_builtin_sym_end,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
  [905] = 5,
    ACTIONS(305), 1,
      sym__any_line,
    STATE(59), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(252), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(250), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [925] = 6,
    ACTIONS(212), 1,
      sym__parenthetical_line,
    ACTIONS(214), 1,
      sym__lyric_line,
    ACTIONS(216), 1,
      sym__any_line,
    STATE(50), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(28), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [947] = 5,
    ACTIONS(199), 1,
      sym__scene_word,
    ACTIONS(310), 1,
      sym__blank,
    STATE(41), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(308), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [966] = 5,
    ACTIONS(312), 1,
      ts_builtin_sym_end,
    ACTIONS(316), 1,
      sym__any_line,
    STATE(47), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(314), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [985] = 5,
    ACTIONS(248), 1,
      ts_builtin_sym_end,
    ACTIONS(319), 1,
      sym__any_line,
    STATE(51), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(250), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1004] = 7,
    ACTIONS(321), 1,
      ts_builtin_sym_end,
    ACTIONS(323), 1,
      sym__scene_number,
    ACTIONS(325), 1,
      anon_sym_DASH,
    ACTIONS(327), 1,
      sym__scene_eol,
    ACTIONS(329), 1,
      sym__blank,
    STATE(38), 1,
      sym__scene_dash,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1027] = 5,
    ACTIONS(331), 1,
      ts_builtin_sym_end,
    ACTIONS(335), 1,
      sym__lyric_line,
    STATE(53), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(333), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1046] = 5,
    ACTIONS(337), 1,
      ts_builtin_sym_end,
    ACTIONS(341), 1,
      sym__any_line,
    STATE(47), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(339), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1065] = 6,
    ACTIONS(319), 1,
      sym__any_line,
    ACTIONS(343), 1,
      ts_builtin_sym_end,
    ACTIONS(346), 1,
      sym__blank,
    STATE(51), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(250), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [1086] = 5,
    ACTIONS(349), 1,
      ts_builtin_sym_end,
    ACTIONS(353), 1,
      sym__lyric_line,
    STATE(53), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(351), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1105] = 3,
    ACTIONS(356), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(358), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1119] = 4,
    ACTIONS(360), 1,
      ts_builtin_sym_end,
    ACTIONS(363), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(185), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [1135] = 5,
    ACTIONS(346), 1,
      sym__blank,
    ACTIONS(366), 1,
      sym__any_line,
    STATE(59), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(250), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [1153] = 4,
    ACTIONS(366), 1,
      sym__any_line,
    STATE(59), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(250), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1169] = 3,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(208), 2,
      sym__scene_word,
      sym__blank,
    ACTIONS(206), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [1183] = 4,
    ACTIONS(368), 1,
      sym__any_line,
    STATE(62), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(339), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1199] = 3,
    ACTIONS(370), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(372), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [1213] = 4,
    STATE(90), 1,
      sym_transition,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(374), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(376), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [1229] = 4,
    ACTIONS(378), 1,
      sym__any_line,
    STATE(62), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(314), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1245] = 4,
    ACTIONS(381), 1,
      sym__lyric_line,
    STATE(64), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(333), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1261] = 4,
    ACTIONS(383), 1,
      sym__lyric_line,
    STATE(64), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(351), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1277] = 3,
    ACTIONS(386), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(388), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1291] = 4,
    ACTIONS(392), 1,
      sym__centered_line,
    STATE(66), 1,
      aux_sym_centered_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(390), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1306] = 3,
    ACTIONS(363), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(185), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [1319] = 5,
    ACTIONS(395), 1,
      ts_builtin_sym_end,
    ACTIONS(397), 1,
      sym__scene_number,
    ACTIONS(399), 1,
      sym__scene_eol,
    ACTIONS(401), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1336] = 4,
    ACTIONS(403), 1,
      sym__lyric_line,
    STATE(74), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(331), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1351] = 4,
    ACTIONS(407), 1,
      sym__centered_line,
    STATE(66), 1,
      aux_sym_centered_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(405), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1366] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(358), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1377] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(388), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1388] = 5,
    ACTIONS(409), 1,
      ts_builtin_sym_end,
    ACTIONS(411), 1,
      sym__scene_number,
    ACTIONS(413), 1,
      sym__scene_eol,
    ACTIONS(415), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1405] = 4,
    ACTIONS(417), 1,
      sym__lyric_line,
    STATE(74), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(349), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1420] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(372), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [1431] = 4,
    ACTIONS(420), 1,
      ts_builtin_sym_end,
    ACTIONS(422), 1,
      sym__scene_eol,
    ACTIONS(424), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1445] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(252), 3,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
  [1455] = 4,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(426), 1,
      sym__blank,
    STATE(11), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1469] = 4,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(428), 1,
      sym__blank,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1483] = 4,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(428), 1,
      sym__blank,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1497] = 4,
    ACTIONS(430), 1,
      ts_builtin_sym_end,
    ACTIONS(432), 1,
      sym__scene_eol,
    ACTIONS(434), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1511] = 4,
    ACTIONS(436), 1,
      ts_builtin_sym_end,
    ACTIONS(438), 1,
      sym__scene_eol,
    ACTIONS(440), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1525] = 4,
    ACTIONS(442), 1,
      ts_builtin_sym_end,
    ACTIONS(444), 1,
      sym__any_line,
    ACTIONS(446), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1539] = 4,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(428), 1,
      sym__blank,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1553] = 4,
    ACTIONS(448), 1,
      ts_builtin_sym_end,
    ACTIONS(450), 1,
      sym__scene_eol,
    ACTIONS(452), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1567] = 4,
    ACTIONS(428), 1,
      sym__blank,
    ACTIONS(454), 1,
      ts_builtin_sym_end,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1581] = 4,
    ACTIONS(456), 1,
      ts_builtin_sym_end,
    ACTIONS(458), 1,
      sym__scene_eol,
    ACTIONS(460), 1,
      sym__blank,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1595] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(462), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1604] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(464), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1613] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(466), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1622] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(468), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1631] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(470), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1640] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(472), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1649] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(474), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1658] = 3,
    ACTIONS(476), 1,
      sym__scene_word,
    STATE(43), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1669] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(478), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1678] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(480), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1687] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(482), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1696] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(484), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1705] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(486), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1714] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(488), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1723] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(490), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1732] = 3,
    ACTIONS(444), 1,
      sym__any_line,
    ACTIONS(446), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1743] = 3,
    ACTIONS(428), 1,
      sym__blank,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
  [1754] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(492), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1763] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(494), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1772] = 2,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(496), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1781] = 2,
    ACTIONS(206), 1,
      sym__scene_word,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1789] = 2,
    ACTIONS(498), 1,
      ts_builtin_sym_end,
    ACTIONS(284), 2,
      sym_note,
      sym_boneyard,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 31,
  [SMALL_STATE(11)] = 62,
  [SMALL_STATE(12)] = 92,
  [SMALL_STATE(13)] = 122,
  [SMALL_STATE(14)] = 152,
  [SMALL_STATE(15)] = 182,
  [SMALL_STATE(16)] = 211,
  [SMALL_STATE(17)] = 240,
  [SMALL_STATE(18)] = 265,
  [SMALL_STATE(19)] = 305,
  [SMALL_STATE(20)] = 342,
  [SMALL_STATE(21)] = 368,
  [SMALL_STATE(22)] = 400,
  [SMALL_STATE(23)] = 428,
  [SMALL_STATE(24)] = 451,
  [SMALL_STATE(25)] = 476,
  [SMALL_STATE(26)] = 505,
  [SMALL_STATE(27)] = 533,
  [SMALL_STATE(28)] = 551,
  [SMALL_STATE(29)] = 579,
  [SMALL_STATE(30)] = 599,
  [SMALL_STATE(31)] = 621,
  [SMALL_STATE(32)] = 649,
  [SMALL_STATE(33)] = 672,
  [SMALL_STATE(34)] = 689,
  [SMALL_STATE(35)] = 714,
  [SMALL_STATE(36)] = 733,
  [SMALL_STATE(37)] = 758,
  [SMALL_STATE(38)] = 773,
  [SMALL_STATE(39)] = 799,
  [SMALL_STATE(40)] = 821,
  [SMALL_STATE(41)] = 843,
  [SMALL_STATE(42)] = 863,
  [SMALL_STATE(43)] = 885,
  [SMALL_STATE(44)] = 905,
  [SMALL_STATE(45)] = 925,
  [SMALL_STATE(46)] = 947,
  [SMALL_STATE(47)] = 966,
  [SMALL_STATE(48)] = 985,
  [SMALL_STATE(49)] = 1004,
  [SMALL_STATE(50)] = 1027,
  [SMALL_STATE(51)] = 1046,
  [SMALL_STATE(52)] = 1065,
  [SMALL_STATE(53)] = 1086,
  [SMALL_STATE(54)] = 1105,
  [SMALL_STATE(55)] = 1119,
  [SMALL_STATE(56)] = 1135,
  [SMALL_STATE(57)] = 1153,
  [SMALL_STATE(58)] = 1169,
  [SMALL_STATE(59)] = 1183,
  [SMALL_STATE(60)] = 1199,
  [SMALL_STATE(61)] = 1213,
  [SMALL_STATE(62)] = 1229,
  [SMALL_STATE(63)] = 1245,
  [SMALL_STATE(64)] = 1261,
  [SMALL_STATE(65)] = 1277,
  [SMALL_STATE(66)] = 1291,
  [SMALL_STATE(67)] = 1306,
  [SMALL_STATE(68)] = 1319,
  [SMALL_STATE(69)] = 1336,
  [SMALL_STATE(70)] = 1351,
  [SMALL_STATE(71)] = 1366,
  [SMALL_STATE(72)] = 1377,
  [SMALL_STATE(73)] = 1388,
  [SMALL_STATE(74)] = 1405,
  [SMALL_STATE(75)] = 1420,
  [SMALL_STATE(76)] = 1431,
  [SMALL_STATE(77)] = 1445,
  [SMALL_STATE(78)] = 1455,
  [SMALL_STATE(79)] = 1469,
  [SMALL_STATE(80)] = 1483,
  [SMALL_STATE(81)] = 1497,
  [SMALL_STATE(82)] = 1511,
  [SMALL_STATE(83)] = 1525,
  [SMALL_STATE(84)] = 1539,
  [SMALL_STATE(85)] = 1553,
  [SMALL_STATE(86)] = 1567,
  [SMALL_STATE(87)] = 1581,
  [SMALL_STATE(88)] = 1595,
  [SMALL_STATE(89)] = 1604,
  [SMALL_STATE(90)] = 1613,
  [SMALL_STATE(91)] = 1622,
  [SMALL_STATE(92)] = 1631,
  [SMALL_STATE(93)] = 1640,
  [SMALL_STATE(94)] = 1649,
  [SMALL_STATE(95)] = 1658,
  [SMALL_STATE(96)] = 1669,
  [SMALL_STATE(97)] = 1678,
  [SMALL_STATE(98)] = 1687,
  [SMALL_STATE(99)] = 1696,
  [SMALL_STATE(100)] = 1705,
  [SMALL_STATE(101)] = 1714,
  [SMALL_STATE(102)] = 1723,
  [SMALL_STATE(103)] = 1732,
  [SMALL_STATE(104)] = 1743,
  [SMALL_STATE(105)] = 1754,
  [SMALL_STATE(106)] = 1763,
  [SMALL_STATE(107)] = 1772,
  [SMALL_STATE(108)] = 1781,
  [SMALL_STATE(109)] = 1789,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 2, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 3, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(19),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(94),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(56),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(106),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(70),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(44),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(77),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(69),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(96),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(103),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(107),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(57),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_page, 1, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_page, 1, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 9),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 9),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 8),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 8),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 3, 0, 16),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 3, 0, 16),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 17),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 17),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 17), SHIFT_REPEAT(17),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [121] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 7),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 7),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 1), REDUCE(sym__scene_start_line, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 1, 0, 0),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 1, 2, 1), REDUCE(sym__scene_start_line, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 5),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(46),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(85),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(99),
  [176] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 5),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__scene_start_line, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 2, 0, 0),
  [187] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [190] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location, 1, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_location, 1, 0, 0), SHIFT(108),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_location, 1, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__scene_dash, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_dash, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialogue, 2, 2, 11),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [216] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialogue, 2, 2, 11),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_location_repeat1, 1, 0, 0), REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [223] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 1, 0, 0), REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [226] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 3),
  [229] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(97),
  [232] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 3),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [243] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 1, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 1, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character, 1, 0, 0),
  [254] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(51),
  [257] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [259] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [263] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [266] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [269] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 13),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 13),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0), SHIFT_REPEAT(108),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0),
  [293] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location, 2, 0, 0),
  [300] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_location, 2, 0, 0), SHIFT(108),
  [303] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_location, 2, 0, 0),
  [305] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(59),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 1, 1, 0),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 1, 1, 0),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [316] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [319] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 2, 2, 4),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 2, 2, 4),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lyric, 1, 0, 0),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_lyric, 1, 0, 0),
  [335] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 2, 0, 0),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [343] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [346] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [351] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [353] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [360] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 2, 2, 1), REDUCE(sym__scene_start_line, 2, 0, 0),
  [363] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 2, 2, 1), REDUCE(sym__scene_start_line, 2, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__scene_start_line, 3, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 3, 0, 0),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 1, 0, 0),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [378] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [381] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [383] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 10),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 10),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0),
  [392] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 15),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [401] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 15),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_centered, 1, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 19),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [415] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 19),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 12),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [424] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 12),
  [426] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 18),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [434] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 18),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 20),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [440] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 20),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 2),
  [444] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [446] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 1, 0, 2),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 14),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [452] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 14),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 4, 0, 0),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 21),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [460] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 5, 2, 21),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 15),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 13),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 2, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 6),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 14),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 4),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_synopsis, 1, 0, 0),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 3),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 18),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 5),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 19),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 20),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 6, 2, 21),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 12),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_page_break, 1, 0, 0),
  [498] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_fountain(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

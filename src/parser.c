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
#define STATE_COUNT 106
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 5
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 20

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
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 1},
  [7] = {.index = 9, .length = 1},
  [8] = {.index = 10, .length = 2},
  [10] = {.index = 12, .length = 1},
  [11] = {.index = 13, .length = 3},
  [12] = {.index = 16, .length = 2},
  [13] = {.index = 18, .length = 2},
  [14] = {.index = 20, .length = 2},
  [15] = {.index = 22, .length = 2},
  [16] = {.index = 24, .length = 3},
  [17] = {.index = 27, .length = 3},
  [18] = {.index = 30, .length = 3},
  [19] = {.index = 33, .length = 4},
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
    [1] = alias_sym_section_title,
  },
  [6] = {
    [0] = alias_sym_title_value,
  },
  [9] = {
    [0] = alias_sym_dialogue_line,
  },
  [11] = {
    [0] = alias_sym_scene_prefix,
    [2] = alias_sym_scene_number,
  },
  [12] = {
    [0] = alias_sym_scene_prefix,
    [2] = alias_sym_scene_number,
  },
  [13] = {
    [0] = alias_sym_scene_prefix,
  },
  [16] = {
    [0] = alias_sym_scene_prefix,
    [3] = alias_sym_scene_number,
  },
  [17] = {
    [0] = alias_sym_scene_prefix,
  },
  [18] = {
    [0] = alias_sym_scene_prefix,
    [3] = alias_sym_scene_number,
  },
  [19] = {
    [0] = alias_sym_scene_prefix,
    [4] = alias_sym_scene_number,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
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
  [24] = 21,
  [25] = 22,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 26,
  [32] = 32,
  [33] = 27,
  [34] = 29,
  [35] = 28,
  [36] = 36,
  [37] = 37,
  [38] = 32,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 41,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 46,
  [55] = 45,
  [56] = 56,
  [57] = 57,
  [58] = 44,
  [59] = 59,
  [60] = 49,
  [61] = 51,
  [62] = 50,
  [63] = 56,
  [64] = 57,
  [65] = 65,
  [66] = 66,
  [67] = 52,
  [68] = 68,
  [69] = 49,
  [70] = 59,
  [71] = 71,
  [72] = 50,
  [73] = 73,
  [74] = 74,
  [75] = 75,
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
  [103] = 103,
  [104] = 74,
  [105] = 105,
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
  [16] = {.lex_state = 31},
  [17] = {.lex_state = 32},
  [18] = {.lex_state = 33},
  [19] = {.lex_state = 33},
  [20] = {.lex_state = 33},
  [21] = {.lex_state = 33},
  [22] = {.lex_state = 33},
  [23] = {.lex_state = 33},
  [24] = {.lex_state = 33},
  [25] = {.lex_state = 33},
  [26] = {.lex_state = 37},
  [27] = {.lex_state = 33},
  [28] = {.lex_state = 33},
  [29] = {.lex_state = 37},
  [30] = {.lex_state = 34},
  [31] = {.lex_state = 37},
  [32] = {.lex_state = 36},
  [33] = {.lex_state = 33},
  [34] = {.lex_state = 37},
  [35] = {.lex_state = 33},
  [36] = {.lex_state = 35},
  [37] = {.lex_state = 34},
  [38] = {.lex_state = 36},
  [39] = {.lex_state = 34},
  [40] = {.lex_state = 34},
  [41] = {.lex_state = 37},
  [42] = {.lex_state = 35},
  [43] = {.lex_state = 37},
  [44] = {.lex_state = 38},
  [45] = {.lex_state = 38},
  [46] = {.lex_state = 38},
  [47] = {.lex_state = 34},
  [48] = {.lex_state = 35},
  [49] = {.lex_state = 37},
  [50] = {.lex_state = 37},
  [51] = {.lex_state = 38},
  [52] = {.lex_state = 38},
  [53] = {.lex_state = 41},
  [54] = {.lex_state = 38},
  [55] = {.lex_state = 38},
  [56] = {.lex_state = 37},
  [57] = {.lex_state = 38},
  [58] = {.lex_state = 38},
  [59] = {.lex_state = 37},
  [60] = {.lex_state = 37},
  [61] = {.lex_state = 38},
  [62] = {.lex_state = 37},
  [63] = {.lex_state = 37},
  [64] = {.lex_state = 38},
  [65] = {.lex_state = 35},
  [66] = {.lex_state = 40},
  [67] = {.lex_state = 38},
  [68] = {.lex_state = 35},
  [69] = {.lex_state = 41},
  [70] = {.lex_state = 37},
  [71] = {.lex_state = 40},
  [72] = {.lex_state = 41},
  [73] = {.lex_state = 37},
  [74] = {.lex_state = 39},
  [75] = {.lex_state = 41},
  [76] = {.lex_state = 35},
  [77] = {.lex_state = 41},
  [78] = {.lex_state = 35},
  [79] = {.lex_state = 35},
  [80] = {.lex_state = 35},
  [81] = {.lex_state = 35},
  [82] = {.lex_state = 39},
  [83] = {.lex_state = 41},
  [84] = {.lex_state = 41},
  [85] = {.lex_state = 41},
  [86] = {.lex_state = 41},
  [87] = {.lex_state = 41},
  [88] = {.lex_state = 41},
  [89] = {.lex_state = 41},
  [90] = {.lex_state = 41},
  [91] = {.lex_state = 41},
  [92] = {.lex_state = 41},
  [93] = {.lex_state = 41},
  [94] = {.lex_state = 41},
  [95] = {.lex_state = 41},
  [96] = {.lex_state = 41},
  [97] = {.lex_state = 21},
  [98] = {.lex_state = 41},
  [99] = {.lex_state = 41},
  [100] = {.lex_state = 41},
  [101] = {.lex_state = 41},
  [102] = {.lex_state = 41},
  [103] = {.lex_state = 41},
  [104] = {.lex_state = 39},
  [105] = {.lex_state = 35},
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
    [sym_screenplay] = STATE(105),
    [sym__block] = STATE(84),
    [sym_title_page] = STATE(2),
    [sym_title_entry] = STATE(9),
    [sym_dialogue] = STATE(84),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(84),
    [sym_scene_heading] = STATE(84),
    [sym_transition] = STATE(84),
    [sym_centered] = STATE(84),
    [sym_synopsis] = STATE(84),
    [sym_section] = STATE(84),
    [sym_page_break] = STATE(84),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat1] = STATE(4),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_title_page_repeat1] = STATE(9),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
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
    [sym__block] = STATE(83),
    [sym_dialogue] = STATE(83),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(83),
    [sym_scene_heading] = STATE(83),
    [sym_transition] = STATE(83),
    [sym_centered] = STATE(83),
    [sym_synopsis] = STATE(83),
    [sym_section] = STATE(83),
    [sym_page_break] = STATE(83),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat1] = STATE(3),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
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
    [sym__block] = STATE(77),
    [sym_dialogue] = STATE(77),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(77),
    [sym_scene_heading] = STATE(77),
    [sym_transition] = STATE(77),
    [sym_centered] = STATE(77),
    [sym_synopsis] = STATE(77),
    [sym_section] = STATE(77),
    [sym_page_break] = STATE(77),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat1] = STATE(15),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
    [ts_builtin_sym_end] = ACTIONS(39),
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
    [sym__blank] = ACTIONS(41),
  },
  [4] = {
    [sym__block] = STATE(83),
    [sym_dialogue] = STATE(83),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(83),
    [sym_scene_heading] = STATE(83),
    [sym_transition] = STATE(83),
    [sym_centered] = STATE(83),
    [sym_synopsis] = STATE(83),
    [sym_section] = STATE(83),
    [sym_page_break] = STATE(83),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat1] = STATE(15),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
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
    [sym__blank] = ACTIONS(41),
  },
  [5] = {
    [sym__block] = STATE(83),
    [sym_dialogue] = STATE(83),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(83),
    [sym_scene_heading] = STATE(83),
    [sym_transition] = STATE(83),
    [sym_centered] = STATE(83),
    [sym_synopsis] = STATE(83),
    [sym_section] = STATE(83),
    [sym_page_break] = STATE(83),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
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
  [6] = {
    [sym__block] = STATE(103),
    [sym_dialogue] = STATE(103),
    [sym_character] = STATE(43),
    [sym_lyric] = STATE(103),
    [sym_scene_heading] = STATE(103),
    [sym_transition] = STATE(103),
    [sym_centered] = STATE(103),
    [sym_synopsis] = STATE(103),
    [sym_section] = STATE(103),
    [sym_page_break] = STATE(103),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(55),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_prefix] = ACTIONS(45),
    [sym__forced_scene_line] = ACTIONS(48),
    [sym__transition_line] = ACTIONS(51),
    [sym__forced_transition_line] = ACTIONS(54),
    [sym__centered_line] = ACTIONS(57),
    [sym__character_line] = ACTIONS(60),
    [sym__forced_character_line] = ACTIONS(63),
    [sym__lyric_line] = ACTIONS(66),
    [sym__synopsis_line] = ACTIONS(69),
    [sym__section_marker] = ACTIONS(72),
    [sym__page_break_line] = ACTIONS(75),
    [sym__forced_action_line] = ACTIONS(78),
    [sym__any_line] = ACTIONS(78),
  },
  [7] = {
    [sym__block] = STATE(77),
    [sym_dialogue] = STATE(77),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(77),
    [sym_scene_heading] = STATE(77),
    [sym_transition] = STATE(77),
    [sym_centered] = STATE(77),
    [sym_synopsis] = STATE(77),
    [sym_section] = STATE(77),
    [sym_page_break] = STATE(77),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
    [ts_builtin_sym_end] = ACTIONS(39),
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
    [sym__block] = STATE(75),
    [sym_dialogue] = STATE(75),
    [sym_character] = STATE(41),
    [sym_lyric] = STATE(75),
    [sym_scene_heading] = STATE(75),
    [sym_transition] = STATE(75),
    [sym_centered] = STATE(75),
    [sym_synopsis] = STATE(75),
    [sym_section] = STATE(75),
    [sym_page_break] = STATE(75),
    [sym_action] = STATE(53),
    [sym__scene_start_line] = STATE(45),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_lyric_repeat1] = STATE(69),
    [aux_sym_centered_repeat1] = STATE(71),
    [ts_builtin_sym_end] = ACTIONS(81),
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
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(31), 1,
      sym__title_key,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(10), 2,
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
    ACTIONS(87), 1,
      ts_builtin_sym_end,
    ACTIONS(91), 1,
      sym__title_key,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(10), 2,
      sym_title_entry,
      aux_sym_title_page_repeat1,
    ACTIONS(89), 14,
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
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(119), 1,
      sym__blank,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(117), 13,
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
  [211] = 3,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(124), 15,
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
  [236] = 5,
    ACTIONS(41), 1,
      sym__blank,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(126), 13,
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
    STATE(30), 1,
      aux_sym_location_repeat1,
    STATE(48), 1,
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
      sym__scene_dash,
    STATE(25), 1,
      aux_sym__scene_start_line_repeat1,
    STATE(30), 1,
      aux_sym_location_repeat1,
    STATE(48), 1,
      sym_location,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(139), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [342] = 5,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(20), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(154), 3,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
    ACTIONS(157), 5,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [366] = 9,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    ACTIONS(162), 1,
      sym__scene_word,
    ACTIONS(165), 1,
      sym__scene_number,
    ACTIONS(170), 1,
      sym__scene_eol,
    ACTIONS(173), 1,
      sym__blank,
    STATE(47), 1,
      aux_sym_location_repeat1,
    STATE(68), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 4,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [398] = 6,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
    ACTIONS(180), 1,
      sym__scene_eol,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(20), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(178), 3,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
    ACTIONS(182), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [424] = 4,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(23), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(184), 3,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
    ACTIONS(157), 5,
      sym__scene_eol,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [445] = 8,
    ACTIONS(162), 1,
      sym__scene_word,
    ACTIONS(165), 1,
      sym__scene_number,
    ACTIONS(170), 1,
      sym__scene_eol,
    ACTIONS(173), 1,
      sym__blank,
    STATE(47), 1,
      aux_sym_location_repeat1,
    STATE(68), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 4,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [474] = 5,
    ACTIONS(189), 1,
      sym__scene_eol,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(23), 2,
      sym__scene_dash,
      aux_sym__scene_start_line_repeat1,
    ACTIONS(187), 3,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
    ACTIONS(182), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [497] = 8,
    ACTIONS(191), 1,
      ts_builtin_sym_end,
    ACTIONS(193), 1,
      sym__parenthetical_line,
    ACTIONS(196), 1,
      sym__lyric_line,
    ACTIONS(199), 1,
      sym__any_line,
    ACTIONS(202), 1,
      sym__blank,
    STATE(49), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(26), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [525] = 5,
    ACTIONS(204), 1,
      ts_builtin_sym_end,
    ACTIONS(207), 1,
      sym__scene_eol,
    ACTIONS(210), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 6,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [547] = 4,
    ACTIONS(213), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
    ACTIONS(216), 5,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__blank,
  [567] = 8,
    ACTIONS(219), 1,
      ts_builtin_sym_end,
    ACTIONS(221), 1,
      sym__parenthetical_line,
    ACTIONS(223), 1,
      sym__lyric_line,
    ACTIONS(225), 1,
      sym__any_line,
    ACTIONS(227), 1,
      sym__blank,
    STATE(49), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(26), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [595] = 8,
    ACTIONS(231), 1,
      sym__scene_word,
    ACTIONS(233), 1,
      anon_sym_DASH,
    ACTIONS(236), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat1,
    STATE(42), 1,
      aux_sym_location_repeat2,
    STATE(97), 1,
      sym__scene_dash,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(229), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [623] = 7,
    ACTIONS(202), 1,
      sym__blank,
    ACTIONS(238), 1,
      sym__parenthetical_line,
    ACTIONS(241), 1,
      sym__lyric_line,
    ACTIONS(244), 1,
      sym__any_line,
    STATE(60), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(31), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [648] = 6,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
    ACTIONS(253), 1,
      sym__any_line,
    STATE(44), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(251), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(249), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [671] = 4,
    ACTIONS(207), 1,
      sym__scene_eol,
    ACTIONS(210), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 6,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [690] = 7,
    ACTIONS(227), 1,
      sym__blank,
    ACTIONS(256), 1,
      sym__parenthetical_line,
    ACTIONS(258), 1,
      sym__lyric_line,
    ACTIONS(260), 1,
      sym__any_line,
    STATE(60), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(31), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [715] = 3,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(168), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
    ACTIONS(216), 5,
      sym__scene_word,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
      sym__blank,
  [732] = 6,
    ACTIONS(266), 1,
      anon_sym_DASH,
    ACTIONS(269), 1,
      sym__blank,
    STATE(36), 1,
      aux_sym_location_repeat2,
    STATE(97), 1,
      sym__scene_dash,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(262), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [754] = 5,
    ACTIONS(231), 1,
      sym__scene_word,
    ACTIONS(269), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(262), 4,
      ts_builtin_sym_end,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
  [774] = 5,
    ACTIONS(271), 1,
      sym__any_line,
    STATE(58), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(251), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(249), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [794] = 8,
    ACTIONS(274), 1,
      ts_builtin_sym_end,
    ACTIONS(276), 1,
      sym__scene_word,
    ACTIONS(278), 1,
      sym__scene_number,
    ACTIONS(280), 1,
      sym__scene_eol,
    ACTIONS(282), 1,
      sym__blank,
    STATE(47), 1,
      aux_sym_location_repeat1,
    STATE(65), 1,
      sym_time,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [820] = 5,
    ACTIONS(286), 1,
      sym__scene_word,
    ACTIONS(289), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(284), 4,
      ts_builtin_sym_end,
      sym__scene_number,
      anon_sym_DASH,
      sym__scene_eol,
  [840] = 6,
    ACTIONS(221), 1,
      sym__parenthetical_line,
    ACTIONS(223), 1,
      sym__lyric_line,
    ACTIONS(225), 1,
      sym__any_line,
    STATE(49), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(29), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [862] = 6,
    ACTIONS(293), 1,
      anon_sym_DASH,
    ACTIONS(296), 1,
      sym__blank,
    STATE(36), 1,
      aux_sym_location_repeat2,
    STATE(97), 1,
      sym__scene_dash,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(291), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [884] = 6,
    ACTIONS(256), 1,
      sym__parenthetical_line,
    ACTIONS(258), 1,
      sym__lyric_line,
    ACTIONS(260), 1,
      sym__any_line,
    STATE(60), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(34), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [906] = 5,
    ACTIONS(298), 1,
      ts_builtin_sym_end,
    ACTIONS(302), 1,
      sym__any_line,
    STATE(51), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(300), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [925] = 5,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
    ACTIONS(304), 1,
      sym__any_line,
    STATE(44), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(249), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [944] = 6,
    ACTIONS(304), 1,
      sym__any_line,
    ACTIONS(306), 1,
      ts_builtin_sym_end,
    ACTIONS(309), 1,
      sym__blank,
    STATE(44), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(249), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [965] = 5,
    ACTIONS(231), 1,
      sym__scene_word,
    ACTIONS(314), 1,
      sym__blank,
    STATE(40), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(312), 3,
      ts_builtin_sym_end,
      sym__scene_number,
      sym__scene_eol,
  [984] = 7,
    ACTIONS(316), 1,
      ts_builtin_sym_end,
    ACTIONS(318), 1,
      sym__scene_number,
    ACTIONS(320), 1,
      anon_sym_DASH,
    ACTIONS(322), 1,
      sym__scene_eol,
    ACTIONS(324), 1,
      sym__blank,
    STATE(39), 1,
      sym__scene_dash,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1007] = 5,
    ACTIONS(326), 1,
      ts_builtin_sym_end,
    ACTIONS(330), 1,
      sym__lyric_line,
    STATE(50), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(328), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1026] = 5,
    ACTIONS(332), 1,
      ts_builtin_sym_end,
    ACTIONS(336), 1,
      sym__lyric_line,
    STATE(50), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(334), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1045] = 5,
    ACTIONS(339), 1,
      ts_builtin_sym_end,
    ACTIONS(343), 1,
      sym__any_line,
    STATE(51), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(341), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1064] = 4,
    ACTIONS(346), 1,
      ts_builtin_sym_end,
    ACTIONS(349), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(182), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [1080] = 4,
    STATE(96), 1,
      sym_transition,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(352), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(354), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [1096] = 5,
    ACTIONS(309), 1,
      sym__blank,
    ACTIONS(356), 1,
      sym__any_line,
    STATE(58), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(249), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [1114] = 4,
    ACTIONS(356), 1,
      sym__any_line,
    STATE(58), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(249), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1130] = 3,
    ACTIONS(358), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(360), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1144] = 3,
    ACTIONS(362), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(364), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [1158] = 4,
    ACTIONS(366), 1,
      sym__any_line,
    STATE(61), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(300), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1174] = 3,
    ACTIONS(368), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(370), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1188] = 4,
    ACTIONS(372), 1,
      sym__lyric_line,
    STATE(62), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(328), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1204] = 4,
    ACTIONS(374), 1,
      sym__any_line,
    STATE(61), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(341), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [1220] = 4,
    ACTIONS(377), 1,
      sym__lyric_line,
    STATE(62), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(334), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [1236] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(360), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1247] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(364), 4,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
      sym__blank,
  [1258] = 5,
    ACTIONS(380), 1,
      ts_builtin_sym_end,
    ACTIONS(382), 1,
      sym__scene_number,
    ACTIONS(384), 1,
      sym__scene_eol,
    ACTIONS(386), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1275] = 4,
    ACTIONS(390), 1,
      sym__centered_line,
    STATE(66), 1,
      aux_sym_centered_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(388), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1290] = 3,
    ACTIONS(349), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(182), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__any_line,
  [1303] = 5,
    ACTIONS(393), 1,
      ts_builtin_sym_end,
    ACTIONS(395), 1,
      sym__scene_number,
    ACTIONS(397), 1,
      sym__scene_eol,
    ACTIONS(399), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1320] = 4,
    ACTIONS(401), 1,
      sym__lyric_line,
    STATE(72), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(326), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1335] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(370), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [1346] = 4,
    ACTIONS(405), 1,
      sym__centered_line,
    STATE(66), 1,
      aux_sym_centered_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(403), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1361] = 4,
    ACTIONS(407), 1,
      sym__lyric_line,
    STATE(72), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(332), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1376] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(251), 3,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
  [1386] = 4,
    ACTIONS(410), 1,
      ts_builtin_sym_end,
    ACTIONS(412), 1,
      sym__any_line,
    ACTIONS(414), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1400] = 4,
    ACTIONS(416), 1,
      ts_builtin_sym_end,
    ACTIONS(418), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1414] = 4,
    ACTIONS(420), 1,
      ts_builtin_sym_end,
    ACTIONS(422), 1,
      sym__scene_eol,
    ACTIONS(424), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1428] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(418), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1442] = 4,
    ACTIONS(426), 1,
      ts_builtin_sym_end,
    ACTIONS(428), 1,
      sym__scene_eol,
    ACTIONS(430), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1456] = 4,
    ACTIONS(432), 1,
      ts_builtin_sym_end,
    ACTIONS(434), 1,
      sym__scene_eol,
    ACTIONS(436), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1470] = 4,
    ACTIONS(438), 1,
      ts_builtin_sym_end,
    ACTIONS(440), 1,
      sym__scene_eol,
    ACTIONS(442), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1484] = 4,
    ACTIONS(444), 1,
      ts_builtin_sym_end,
    ACTIONS(446), 1,
      sym__scene_eol,
    ACTIONS(448), 1,
      sym__blank,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1498] = 4,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(450), 1,
      sym__blank,
    STATE(11), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1512] = 4,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(418), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1526] = 4,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(418), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1540] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(274), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1549] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(452), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1558] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(454), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1567] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(456), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1576] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(458), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1585] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(460), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1594] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(462), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1603] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(464), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1612] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(466), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1621] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(468), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1630] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(470), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1639] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(472), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1648] = 3,
    ACTIONS(474), 1,
      sym__scene_word,
    STATE(37), 1,
      aux_sym_location_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1659] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(476), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1668] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(478), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1677] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(480), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1686] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(482), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1695] = 2,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(484), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1704] = 3,
    ACTIONS(418), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(264), 2,
      sym_note,
      sym_boneyard,
  [1715] = 3,
    ACTIONS(412), 1,
      sym__any_line,
    ACTIONS(414), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [1726] = 2,
    ACTIONS(486), 1,
      ts_builtin_sym_end,
    ACTIONS(264), 2,
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
  [SMALL_STATE(17)] = 236,
  [SMALL_STATE(18)] = 265,
  [SMALL_STATE(19)] = 305,
  [SMALL_STATE(20)] = 342,
  [SMALL_STATE(21)] = 366,
  [SMALL_STATE(22)] = 398,
  [SMALL_STATE(23)] = 424,
  [SMALL_STATE(24)] = 445,
  [SMALL_STATE(25)] = 474,
  [SMALL_STATE(26)] = 497,
  [SMALL_STATE(27)] = 525,
  [SMALL_STATE(28)] = 547,
  [SMALL_STATE(29)] = 567,
  [SMALL_STATE(30)] = 595,
  [SMALL_STATE(31)] = 623,
  [SMALL_STATE(32)] = 648,
  [SMALL_STATE(33)] = 671,
  [SMALL_STATE(34)] = 690,
  [SMALL_STATE(35)] = 715,
  [SMALL_STATE(36)] = 732,
  [SMALL_STATE(37)] = 754,
  [SMALL_STATE(38)] = 774,
  [SMALL_STATE(39)] = 794,
  [SMALL_STATE(40)] = 820,
  [SMALL_STATE(41)] = 840,
  [SMALL_STATE(42)] = 862,
  [SMALL_STATE(43)] = 884,
  [SMALL_STATE(44)] = 906,
  [SMALL_STATE(45)] = 925,
  [SMALL_STATE(46)] = 944,
  [SMALL_STATE(47)] = 965,
  [SMALL_STATE(48)] = 984,
  [SMALL_STATE(49)] = 1007,
  [SMALL_STATE(50)] = 1026,
  [SMALL_STATE(51)] = 1045,
  [SMALL_STATE(52)] = 1064,
  [SMALL_STATE(53)] = 1080,
  [SMALL_STATE(54)] = 1096,
  [SMALL_STATE(55)] = 1114,
  [SMALL_STATE(56)] = 1130,
  [SMALL_STATE(57)] = 1144,
  [SMALL_STATE(58)] = 1158,
  [SMALL_STATE(59)] = 1174,
  [SMALL_STATE(60)] = 1188,
  [SMALL_STATE(61)] = 1204,
  [SMALL_STATE(62)] = 1220,
  [SMALL_STATE(63)] = 1236,
  [SMALL_STATE(64)] = 1247,
  [SMALL_STATE(65)] = 1258,
  [SMALL_STATE(66)] = 1275,
  [SMALL_STATE(67)] = 1290,
  [SMALL_STATE(68)] = 1303,
  [SMALL_STATE(69)] = 1320,
  [SMALL_STATE(70)] = 1335,
  [SMALL_STATE(71)] = 1346,
  [SMALL_STATE(72)] = 1361,
  [SMALL_STATE(73)] = 1376,
  [SMALL_STATE(74)] = 1386,
  [SMALL_STATE(75)] = 1400,
  [SMALL_STATE(76)] = 1414,
  [SMALL_STATE(77)] = 1428,
  [SMALL_STATE(78)] = 1442,
  [SMALL_STATE(79)] = 1456,
  [SMALL_STATE(80)] = 1470,
  [SMALL_STATE(81)] = 1484,
  [SMALL_STATE(82)] = 1498,
  [SMALL_STATE(83)] = 1512,
  [SMALL_STATE(84)] = 1526,
  [SMALL_STATE(85)] = 1540,
  [SMALL_STATE(86)] = 1549,
  [SMALL_STATE(87)] = 1558,
  [SMALL_STATE(88)] = 1567,
  [SMALL_STATE(89)] = 1576,
  [SMALL_STATE(90)] = 1585,
  [SMALL_STATE(91)] = 1594,
  [SMALL_STATE(92)] = 1603,
  [SMALL_STATE(93)] = 1612,
  [SMALL_STATE(94)] = 1621,
  [SMALL_STATE(95)] = 1630,
  [SMALL_STATE(96)] = 1639,
  [SMALL_STATE(97)] = 1648,
  [SMALL_STATE(98)] = 1659,
  [SMALL_STATE(99)] = 1668,
  [SMALL_STATE(100)] = 1677,
  [SMALL_STATE(101)] = 1686,
  [SMALL_STATE(102)] = 1695,
  [SMALL_STATE(103)] = 1704,
  [SMALL_STATE(104)] = 1715,
  [SMALL_STATE(105)] = 1726,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 2, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(19),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(102),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(90),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(71),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(38),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(73),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(69),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(89),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(104),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(88),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(55),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_page, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_page, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 8),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 8),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 7),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 7),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 3, 0, 14),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 3, 0, 14),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 15),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 15),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 15), SHIFT_REPEAT(16),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [119] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 6),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 6),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 1), REDUCE(sym__scene_start_line, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 1, 0, 0),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 1, 2, 1), REDUCE(sym__scene_start_line, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 1),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(47),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(79),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(93),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 1),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__scene_start_line, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 2, 0, 0),
  [184] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [193] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [199] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 3),
  [207] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), SHIFT(87),
  [210] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0), REDUCE(sym_scene_heading, 2, 2, 3),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_location_repeat1, 1, 0, 0), REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [216] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 1, 0, 0), REDUCE(aux_sym__scene_start_line_repeat1, 1, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialogue, 2, 2, 10),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialogue, 2, 2, 10),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location, 1, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_location, 1, 0, 0), SHIFT(97),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_location, 1, 0, 0),
  [238] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [241] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [244] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 1, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 1, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character, 1, 0, 0),
  [253] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(44),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [266] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0), SHIFT_REPEAT(97),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_location_repeat2, 2, 0, 0),
  [271] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(58),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 4),
  [276] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 4),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0),
  [286] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_location_repeat1, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location, 2, 0, 0),
  [293] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_location, 2, 0, 0), SHIFT(97),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_location, 2, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 2, 0, 0),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [306] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [309] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_time, 1, 1, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_time, 1, 1, 0),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 2, 2, 4),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 2, 2, 4),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lyric, 1, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_lyric, 1, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [336] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [341] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [343] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [346] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 2, 2, 1), REDUCE(sym__scene_start_line, 2, 0, 0),
  [349] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 2, 2, 1), REDUCE(sym__scene_start_line, 2, 0, 0),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 1, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [356] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [360] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__scene_start_line, 3, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__scene_start_line, 3, 0, 0),
  [366] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 9),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 9),
  [372] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [374] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [377] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 17),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [386] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 17),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0),
  [390] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 13),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [399] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 13),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_centered, 1, 0, 0),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [407] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 2),
  [412] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [414] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 1, 0, 2),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 4, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 19),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [424] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 5, 2, 19),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 11),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [430] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 11),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 12),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [436] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 3, 2, 12),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 16),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [442] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 16),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 18),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [448] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_heading, 4, 2, 18),
  [450] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 13),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 3),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_page_break, 1, 0, 0),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_synopsis, 1, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 11),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 17),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 3, 2, 1),
  [468] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 18),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 4),
  [472] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 2, 0, 0),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 4, 2, 12),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 6, 2, 19),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 5),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 5, 2, 16),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0),
  [486] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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

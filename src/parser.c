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
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '!', 133,
        '#', 128,
        '(', 201,
        '-', 77,
        '.', 214,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'A', 259,
        'C', 246,
        'D', 222,
        'E', 257,
        'I', 327,
        'N', 252,
        'R', 229,
        'S', 249,
        'T', 241,
        '[', 273,
        'a', 320,
        'c', 300,
        'd', 277,
        'e', 309,
        'i', 328,
        'n', 304,
        'r', 284,
        's', 301,
        't', 295,
        '~', 114,
        '\t', 199,
        ' ', 199,
      );
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(78);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 74,
        '-', 77,
        '/', 62,
        '[', 71,
        '\t', 2,
        ' ', 2,
      );
      if (lookahead != 0) ADVANCE(75);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 37,
        '-', 77,
        '/', 22,
        '[', 31,
        '\t', 3,
        ' ', 3,
      );
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(136);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(20);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == ']') ADVANCE(33);
      if (lookahead != 0) ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(110);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(102);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(92);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(92);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(332);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(332);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '>') ADVANCE(27);
      if (lookahead == '[') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      ADVANCE_MAP(
        '\n', 332,
        '\r', 11,
        '/', 22,
        '>', 100,
        '[', 31,
        '~', 115,
        '\t', 13,
        ' ', 13,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == '\n') ADVANCE(105);
      END_STATE();
    case 15:
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '(') ADVANCE(21);
      if (lookahead == '^') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '(') ADVANCE(326);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == '\r' ||
          lookahead == '*') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(201);
      END_STATE();
    case 19:
      if (lookahead == '(') ADVANCE(326);
      if (lookahead == ')') ADVANCE(330);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(209);
      END_STATE();
    case 20:
      if (lookahead == ')') ADVANCE(111);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == ')') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '*') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '/') ADVANCE(52);
      if (lookahead != 0) ADVANCE(24);
      END_STATE();
    case 24:
      if (lookahead == '*') ADVANCE(23);
      if (lookahead != 0) ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '[') ADVANCE(71);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(25);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '-') ADVANCE(75);
      END_STATE();
    case 26:
      if (lookahead == ':') ADVANCE(10);
      if (lookahead == 'T') ADVANCE(29);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(30);
      END_STATE();
    case 27:
      if (lookahead == '<') ADVANCE(104);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 28:
      if (lookahead == '<') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(28);
      END_STATE();
    case 29:
      if (lookahead == 'O') ADVANCE(26);
      if (lookahead == 'T') ADVANCE(29);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(30);
      END_STATE();
    case 30:
      if (lookahead == 'T') ADVANCE(29);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == '[') ADVANCE(32);
      END_STATE();
    case 32:
      if (lookahead == ']') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(32);
      END_STATE();
    case 33:
      if (lookahead == ']') ADVANCE(51);
      END_STATE();
    case 34:
      if (lookahead == ']') ADVANCE(274);
      if (lookahead == '\r' ||
          lookahead == '*') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(202);
      END_STATE();
    case 35:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(275);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '*') ADVANCE(326);
      END_STATE();
    case 36:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(323);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '*') ADVANCE(326);
      END_STATE();
    case 37:
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 38:
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '*') ADVANCE(326);
      END_STATE();
    case 39:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\t', 137,
        '\n', 332,
        '\r', 11,
        ' ', 137,
        '!', 133,
        '#', 128,
        '.', 213,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'A', 182,
        'C', 170,
        'D', 146,
        'E', 180,
        'I', 196,
        'N', 175,
        'R', 153,
        'S', 172,
        'T', 165,
        '[', 273,
        'a', 320,
        'c', 300,
        'd', 277,
        'e', 309,
        'i', 328,
        'n', 304,
        'r', 284,
        's', 301,
        't', 295,
        '~', 114,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(325);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 40:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\t', 138,
        '\n', 332,
        '\r', 11,
        ' ', 138,
        '!', 133,
        '#', 128,
        '.', 213,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'E', 180,
        'I', 196,
        '[', 273,
        'e', 309,
        'i', 328,
        '~', 114,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(325);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 41:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 69,
        '-', 77,
        '/', 61,
        '>', 70,
        '[', 67,
        '\t', 200,
        ' ', 200,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(66);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 42:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 74,
        '-', 77,
        '/', 62,
        '[', 71,
        '\t', 2,
        ' ', 2,
      );
      if (lookahead != 0) ADVANCE(75);
      END_STATE();
    case 43:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 37,
        '-', 77,
        '/', 22,
        '[', 31,
        '\t', 3,
        ' ', 3,
      );
      END_STATE();
    case 44:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 332,
        '\r', 11,
        '(', 201,
        '/', 210,
        '>', 99,
        '[', 273,
        '~', 114,
        '\t', 207,
        ' ', 207,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 45:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 332,
        '\r', 11,
        '(', 201,
        '/', 210,
        '[', 273,
        '~', 114,
        '\t', 208,
        ' ', 208,
      );
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 46:
      if (eof) ADVANCE(50);
      if (lookahead == '\n') ADVANCE(332);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '>') ADVANCE(99);
      if (lookahead == '[') ADVANCE(273);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(211);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 47:
      if (eof) ADVANCE(50);
      if (lookahead == '\n') ADVANCE(332);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '[') ADVANCE(273);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(212);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 48:
      if (eof) ADVANCE(50);
      if (lookahead == '\n') ADVANCE(332);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead == '>') ADVANCE(27);
      if (lookahead == '[') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 49:
      if (eof) ADVANCE(50);
      ADVANCE_MAP(
        '\n', 332,
        '\r', 11,
        '/', 22,
        '>', 100,
        '[', 31,
        '~', 115,
        '\t', 13,
        ' ', 13,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(30);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_boneyard);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__scene_prefix);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__scene_prefix);
      if (lookahead == '/') ADVANCE(36);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '/') ADVANCE(57);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '#') ADVANCE(76);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(58);
      if (lookahead == '/') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(59);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(73);
      if (lookahead == ']') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(63);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '*') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == ']') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead == ':') ADVANCE(70);
      if (lookahead == 'T') ADVANCE(65);
      if (('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead == 'O') ADVANCE(64);
      if (lookahead == 'T') ADVANCE(65);
      if (('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead == 'T') ADVANCE(65);
      if (('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead == '[') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead == ']') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (('-' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '/') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == ']') ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__scene_word);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__scene_number);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym__scene_eol);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__forced_scene_line);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\t') ADVANCE(87);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == ' ') ADVANCE(80);
      if (lookahead == '(') ADVANCE(82);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == '^') ADVANCE(87);
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(80);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '(') ADVANCE(89);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(83);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '(') ADVANCE(89);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '/') ADVANCE(81);
      if (lookahead != 0) ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '(') ADVANCE(91);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead != 0) ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '(') ADVANCE(82);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == '^') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '(') ADVANCE(83);
      if (lookahead == '^') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(85);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(87);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(88);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(80);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(91);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__transition_line);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__forced_transition_line);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(97);
      if (lookahead == '*') ADVANCE(97);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(97);
      if (lookahead == '/') ADVANCE(94);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(95);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(97);
      if (lookahead == '/') ADVANCE(94);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(97);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead != 0) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(100);
      if (lookahead == '*') ADVANCE(100);
      if (lookahead != 0) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(100);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead != 0) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(93);
      if (lookahead == '\r') ADVANCE(100);
      if (lookahead != 0) ADVANCE(100);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(100);
      if (lookahead != 0) ADVANCE(100);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__centered_line);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(104);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__character_line);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym__forced_character_line);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym__forced_character_line);
      if (lookahead == '\n') ADVANCE(106);
      if (lookahead == '\r') ADVANCE(109);
      if (lookahead == '*') ADVANCE(109);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym__forced_character_line);
      if (lookahead == '\n') ADVANCE(106);
      if (lookahead == '\r') ADVANCE(109);
      if (lookahead == '/') ADVANCE(107);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__forced_character_line);
      if (lookahead == '\n') ADVANCE(106);
      if (lookahead == '\r') ADVANCE(109);
      if (lookahead != 0) ADVANCE(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym__parenthetical_line);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym__parenthetical_line);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(111);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__lyric_line);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym__lyric_line);
      if (lookahead == '\n') ADVANCE(112);
      if (lookahead == '\r') ADVANCE(115);
      if (lookahead == '*') ADVANCE(115);
      if (lookahead != 0) ADVANCE(114);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__lyric_line);
      if (lookahead == '\n') ADVANCE(112);
      if (lookahead == '\r') ADVANCE(115);
      if (lookahead == '/') ADVANCE(113);
      if (lookahead != 0) ADVANCE(114);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym__lyric_line);
      if (lookahead == '\n') ADVANCE(112);
      if (lookahead == '\r') ADVANCE(115);
      if (lookahead != 0) ADVANCE(115);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__synopsis_line);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(116);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead == '*') ADVANCE(121);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(116);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead == '/') ADVANCE(117);
      if (lookahead == '=') ADVANCE(130);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(116);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead == '/') ADVANCE(117);
      if (lookahead == '=') ADVANCE(118);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(116);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead == '/') ADVANCE(117);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(116);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(129);
      if (lookahead == '\r') ADVANCE(121);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym__section_marker);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(123);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(124);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(125);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(126);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(127);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym__page_break_line);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym__page_break_line);
      if (lookahead == '\n') ADVANCE(129);
      if (lookahead == '\r') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym__forced_action_line);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == '\r') ADVANCE(134);
      if (lookahead == '*') ADVANCE(134);
      if (lookahead != 0) ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == '\r') ADVANCE(134);
      if (lookahead == '/') ADVANCE(132);
      if (lookahead != 0) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == '\r') ADVANCE(134);
      if (lookahead != 0) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym__title_key);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym__any_line);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 137,
        '\n', 136,
        '\r', 4,
        ' ', 137,
        '!', 133,
        '#', 128,
        '.', 213,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'A', 182,
        'C', 170,
        'D', 146,
        'E', 180,
        'I', 196,
        'N', 175,
        'R', 153,
        'S', 172,
        'T', 165,
        '[', 273,
        'a', 320,
        'c', 300,
        'd', 277,
        'e', 309,
        'i', 328,
        'n', 304,
        'r', 284,
        's', 301,
        't', 295,
        '~', 114,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(325);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 138,
        '\n', 136,
        '\r', 4,
        ' ', 138,
        '!', 133,
        '#', 128,
        '.', 213,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'E', 180,
        'I', 196,
        '[', 273,
        'e', 309,
        'i', 328,
        '~', 114,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(325);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 53,
        '(', 209,
        '.', 53,
        '/', 38,
        'O', 141,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 53,
        '(', 209,
        '.', 54,
        '/', 36,
        'O', 141,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        ':', 329,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        ':', 135,
        'O', 141,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        ':', 135,
        'S', 144,
        'T', 171,
        '^', 331,
        's', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        ':', 135,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'A', 158,
        'T', 171,
        '^', 331,
        'a', 288,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'A', 188,
        'R', 145,
        'T', 171,
        '^', 331,
        'a', 318,
        'r', 276,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'A', 188,
        'T', 171,
        '^', 331,
        'a', 318,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'A', 150,
        'O', 141,
        'T', 171,
        '^', 331,
        'a', 281,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'C', 157,
        'T', 171,
        '^', 331,
        'c', 286,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'C', 192,
        'T', 171,
        '^', 331,
        'c', 315,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'D', 147,
        'T', 171,
        '^', 331,
        'd', 278,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'D', 166,
        'T', 171,
        '^', 331,
        'd', 296,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'E', 184,
        'T', 171,
        '^', 331,
        'e', 322,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'E', 152,
        'T', 171,
        '^', 331,
        'e', 283,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'E', 179,
        'O', 141,
        'T', 171,
        '^', 331,
        'e', 308,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'E', 144,
        'O', 141,
        'T', 171,
        '^', 331,
        'e', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'E', 144,
        'T', 171,
        '^', 331,
        'e', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'F', 193,
        'T', 171,
        '^', 331,
        'f', 316,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'G', 161,
        'T', 171,
        '^', 331,
        'g', 291,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'H', 174,
        'O', 141,
        'T', 171,
        '^', 331,
        'h', 303,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'H', 192,
        'T', 171,
        '^', 331,
        'h', 315,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'I', 159,
        'T', 171,
        '^', 331,
        'i', 289,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'I', 181,
        'T', 171,
        '^', 331,
        'i', 310,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'I', 173,
        'T', 171,
        '^', 331,
        'i', 302,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'I', 190,
        'T', 171,
        '^', 331,
        'i', 314,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'I', 192,
        'T', 171,
        '^', 331,
        'i', 315,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'L', 157,
        'O', 141,
        'T', 171,
        '^', 331,
        'l', 286,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'N', 144,
        'T', 171,
        '^', 331,
        'n', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'N', 191,
        'P', 185,
        'T', 171,
        '^', 331,
        'n', 317,
        'p', 324,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 169,
        'R', 154,
        'T', 171,
        '^', 331,
        'o', 299,
        'r', 285,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 141,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 183,
        'T', 171,
        '^', 331,
        'o', 321,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 168,
        'T', 171,
        '^', 331,
        'o', 298,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 177,
        'T', 171,
        '^', 331,
        'o', 306,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'O', 194,
        'T', 171,
        '^', 331,
        'o', 319,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'R', 149,
        'T', 171,
        '^', 331,
        'r', 280,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'R', 143,
        'T', 171,
        '^', 331,
        'r', 219,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'R', 162,
        'T', 171,
        '^', 331,
        'r', 292,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'S', 144,
        'T', 171,
        '^', 331,
        's', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'S', 189,
        'T', 171,
        'X', 189,
        '^', 331,
        's', 312,
        'x', 312,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'S', 164,
        'T', 171,
        '^', 331,
        's', 294,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 171,
        'U', 187,
        '^', 331,
        'u', 311,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 171,
        'U', 176,
        '^', 331,
        'u', 305,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 171,
        'V', 163,
        '^', 331,
        'v', 293,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 171,
        'Y', 178,
        '^', 331,
        'y', 307,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 160,
        '^', 331,
        't', 290,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 156,
        '^', 331,
        't', 286,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 139,
        '^', 331,
        't', 275,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 167,
        '^', 331,
        't', 297,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 148,
        '^', 331,
        't', 279,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 142,
        '^', 331,
        't', 220,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 198,
        '^', 331,
        't', 206,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 155,
        '^', 331,
        't', 287,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 38,
        'T', 140,
        '^', 331,
        't', 204,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 186,
        '(', 209,
        '/', 35,
        'N', 195,
        'T', 171,
        '^', 331,
        'n', 313,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\t') ADVANCE(331);
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == ' ') ADVANCE(197);
      if (lookahead == '(') ADVANCE(209);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '^') ADVANCE(331);
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(197);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(197);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 331,
        '\n', 105,
        '\r', 14,
        ' ', 151,
        '(', 209,
        '/', 38,
        'O', 141,
        'T', 171,
        '^', 331,
        '\'', 197,
        '-', 197,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(186);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(186);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '!', 133,
        '#', 128,
        '(', 201,
        '-', 77,
        '.', 214,
        '/', 210,
        '=', 119,
        '>', 95,
        '@', 108,
        'A', 259,
        'C', 246,
        'D', 222,
        'E', 257,
        'I', 327,
        'N', 252,
        'R', 229,
        'S', 249,
        'T', 241,
        '[', 273,
        'a', 320,
        'c', 300,
        'd', 277,
        'e', 309,
        'i', 328,
        'n', 304,
        'r', 284,
        's', 301,
        't', 295,
        '~', 114,
        '\t', 199,
        ' ', 199,
      );
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 78,
        '\r', 1,
        '#', 69,
        '-', 77,
        '/', 61,
        '>', 70,
        '[', 67,
        '\t', 200,
        ' ', 200,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(66);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '(') ADVANCE(326);
      if (lookahead == ')') ADVANCE(111);
      if (lookahead == '/') ADVANCE(18);
      if (lookahead != 0) ADVANCE(201);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == '/') ADVANCE(34);
      if (lookahead == ']') ADVANCE(274);
      if (lookahead != 0) ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '/') ADVANCE(36);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == '.') ADVANCE(54);
      if (lookahead == '/') ADVANCE(36);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(227);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(282);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '(', 201,
        '/', 210,
        '>', 99,
        '[', 273,
        '~', 114,
        '\t', 207,
        ' ', 207,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '(', 201,
        '/', 210,
        '[', 273,
        '~', 114,
        '\t', 208,
        ' ', 208,
      );
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '(') ADVANCE(326);
      if (lookahead == ')') ADVANCE(330);
      if (lookahead == '/') ADVANCE(19);
      if (lookahead != 0) ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '>') ADVANCE(99);
      if (lookahead == '[') ADVANCE(273);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(211);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(210);
      if (lookahead == '[') ADVANCE(273);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(212);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(86);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(325);
      if (('\t' <= lookahead && lookahead <= '\f')) ADVANCE(326);
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(88);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(80);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ' ||
          lookahead == '.') ADVANCE(326);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(329);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == 'S') ADVANCE(218);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 's') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(135);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(220);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ':') ADVANCE(135);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A') ADVANCE(234);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'a') ADVANCE(288);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '/', 38,
        'A', 265,
        'R', 221,
        'T', 248,
        'a', 318,
        'r', 276,
      );
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A') ADVANCE(265);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'a') ADVANCE(318);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A') ADVANCE(226);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'a') ADVANCE(281);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'C') ADVANCE(233);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'c') ADVANCE(286);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'C') ADVANCE(271);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'c') ADVANCE(315);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'D') ADVANCE(223);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'd') ADVANCE(278);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'D') ADVANCE(242);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'd') ADVANCE(296);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E') ADVANCE(261);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'e') ADVANCE(322);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E') ADVANCE(228);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'e') ADVANCE(283);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E') ADVANCE(256);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'e') ADVANCE(308);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E') ADVANCE(218);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'e') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E') ADVANCE(218);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'e') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'F') ADVANCE(270);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'f') ADVANCE(316);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'G') ADVANCE(237);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'g') ADVANCE(291);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'H') ADVANCE(251);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'h') ADVANCE(303);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'H') ADVANCE(271);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'h') ADVANCE(315);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I') ADVANCE(235);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'i') ADVANCE(289);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I') ADVANCE(258);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'i') ADVANCE(310);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I') ADVANCE(250);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'i') ADVANCE(302);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I') ADVANCE(268);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'i') ADVANCE(314);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I') ADVANCE(271);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'i') ADVANCE(315);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'L') ADVANCE(233);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'l') ADVANCE(286);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'N') ADVANCE(218);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'n') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '/', 38,
        'N', 269,
        'P', 262,
        'T', 248,
        'n', 317,
        'p', 324,
      );
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '/', 38,
        'O', 245,
        'R', 230,
        'T', 248,
        'o', 299,
        'r', 285,
      );
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(215);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(260);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'o') ADVANCE(321);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(244);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'o') ADVANCE(298);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(254);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'o') ADVANCE(306);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O') ADVANCE(272);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'o') ADVANCE(319);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R') ADVANCE(225);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(280);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R') ADVANCE(217);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(219);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R') ADVANCE(238);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'r') ADVANCE(292);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'S') ADVANCE(218);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 's') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 136,
        '\r', 4,
        '/', 38,
        'S', 266,
        'T', 248,
        'X', 266,
        's', 312,
        'x', 312,
      );
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'S') ADVANCE(240);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 's') ADVANCE(294);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'U') ADVANCE(264);
      if (lookahead == 'u') ADVANCE(311);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'U') ADVANCE(253);
      if (lookahead == 'u') ADVANCE(305);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'V') ADVANCE(239);
      if (lookahead == 'v') ADVANCE(293);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'Y') ADVANCE(255);
      if (lookahead == 'y') ADVANCE(307);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(236);
      if (lookahead == 't') ADVANCE(290);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(232);
      if (lookahead == 't') ADVANCE(286);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(247);
      if (lookahead == 't') ADVANCE(275);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(203);
      if (lookahead == 't') ADVANCE(204);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(243);
      if (lookahead == 't') ADVANCE(297);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(224);
      if (lookahead == 't') ADVANCE(279);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(205);
      if (lookahead == 't') ADVANCE(206);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(216);
      if (lookahead == 't') ADVANCE(220);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T') ADVANCE(231);
      if (lookahead == 't') ADVANCE(287);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '[') ADVANCE(202);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ']') ADVANCE(51);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(53);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(288);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(318);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(276);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(318);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(281);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(286);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(315);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(278);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(296);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(322);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(283);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(220);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(308);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(316);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(291);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(303);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(315);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(289);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(310);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(302);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(314);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(315);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(286);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(220);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(317);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(324);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(299);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(285);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(321);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(298);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(306);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(319);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(280);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(219);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(292);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(220);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(312);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(312);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(294);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(290);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(275);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(204);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(297);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(220);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(206);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(279);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(286);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(287);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(311);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(305);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(293);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(312);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(307);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(325);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(197);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead == 'N') ADVANCE(267);
      if (lookahead == 'T') ADVANCE(248);
      if (lookahead == 'n') ADVANCE(313);
      if (lookahead == ' ' ||
          ('.' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(263);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(313);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(92);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(329);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '(') ADVANCE(209);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '^') ADVANCE(331);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(330);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(105);
      if (lookahead == '\r') ADVANCE(14);
      if (lookahead == '/') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(331);
      if (lookahead != 0) ADVANCE(326);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym__blank);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 39},
  [2] = {.lex_state = 40},
  [3] = {.lex_state = 40},
  [4] = {.lex_state = 40},
  [5] = {.lex_state = 40},
  [6] = {.lex_state = 40},
  [7] = {.lex_state = 40},
  [8] = {.lex_state = 40},
  [9] = {.lex_state = 39},
  [10] = {.lex_state = 39},
  [11] = {.lex_state = 39},
  [12] = {.lex_state = 39},
  [13] = {.lex_state = 39},
  [14] = {.lex_state = 39},
  [15] = {.lex_state = 40},
  [16] = {.lex_state = 40},
  [17] = {.lex_state = 39},
  [18] = {.lex_state = 41},
  [19] = {.lex_state = 41},
  [20] = {.lex_state = 41},
  [21] = {.lex_state = 41},
  [22] = {.lex_state = 41},
  [23] = {.lex_state = 41},
  [24] = {.lex_state = 41},
  [25] = {.lex_state = 41},
  [26] = {.lex_state = 42},
  [27] = {.lex_state = 41},
  [28] = {.lex_state = 45},
  [29] = {.lex_state = 41},
  [30] = {.lex_state = 41},
  [31] = {.lex_state = 45},
  [32] = {.lex_state = 44},
  [33] = {.lex_state = 41},
  [34] = {.lex_state = 45},
  [35] = {.lex_state = 41},
  [36] = {.lex_state = 45},
  [37] = {.lex_state = 41},
  [38] = {.lex_state = 42},
  [39] = {.lex_state = 45},
  [40] = {.lex_state = 43},
  [41] = {.lex_state = 42},
  [42] = {.lex_state = 43},
  [43] = {.lex_state = 42},
  [44] = {.lex_state = 44},
  [45] = {.lex_state = 45},
  [46] = {.lex_state = 42},
  [47] = {.lex_state = 46},
  [48] = {.lex_state = 46},
  [49] = {.lex_state = 43},
  [50] = {.lex_state = 45},
  [51] = {.lex_state = 46},
  [52] = {.lex_state = 46},
  [53] = {.lex_state = 45},
  [54] = {.lex_state = 45},
  [55] = {.lex_state = 46},
  [56] = {.lex_state = 46},
  [57] = {.lex_state = 46},
  [58] = {.lex_state = 42},
  [59] = {.lex_state = 46},
  [60] = {.lex_state = 46},
  [61] = {.lex_state = 49},
  [62] = {.lex_state = 46},
  [63] = {.lex_state = 45},
  [64] = {.lex_state = 45},
  [65] = {.lex_state = 45},
  [66] = {.lex_state = 48},
  [67] = {.lex_state = 46},
  [68] = {.lex_state = 43},
  [69] = {.lex_state = 49},
  [70] = {.lex_state = 48},
  [71] = {.lex_state = 45},
  [72] = {.lex_state = 45},
  [73] = {.lex_state = 43},
  [74] = {.lex_state = 49},
  [75] = {.lex_state = 46},
  [76] = {.lex_state = 43},
  [77] = {.lex_state = 45},
  [78] = {.lex_state = 47},
  [79] = {.lex_state = 49},
  [80] = {.lex_state = 49},
  [81] = {.lex_state = 43},
  [82] = {.lex_state = 43},
  [83] = {.lex_state = 47},
  [84] = {.lex_state = 49},
  [85] = {.lex_state = 43},
  [86] = {.lex_state = 49},
  [87] = {.lex_state = 43},
  [88] = {.lex_state = 49},
  [89] = {.lex_state = 49},
  [90] = {.lex_state = 49},
  [91] = {.lex_state = 49},
  [92] = {.lex_state = 49},
  [93] = {.lex_state = 49},
  [94] = {.lex_state = 49},
  [95] = {.lex_state = 25},
  [96] = {.lex_state = 49},
  [97] = {.lex_state = 49},
  [98] = {.lex_state = 49},
  [99] = {.lex_state = 49},
  [100] = {.lex_state = 49},
  [101] = {.lex_state = 49},
  [102] = {.lex_state = 49},
  [103] = {.lex_state = 47},
  [104] = {.lex_state = 49},
  [105] = {.lex_state = 49},
  [106] = {.lex_state = 49},
  [107] = {.lex_state = 49},
  [108] = {.lex_state = 25},
  [109] = {.lex_state = 43},
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

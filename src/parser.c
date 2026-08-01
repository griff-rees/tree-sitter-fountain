#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 65
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 42
#define ALIAS_COUNT 3
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 10

enum ts_symbol_identifiers {
  sym_note = 1,
  sym_boneyard = 2,
  sym__scene_line = 3,
  sym__forced_scene_line = 4,
  sym__transition_line = 5,
  sym__forced_transition_line = 6,
  sym__centered_line = 7,
  sym__character_line = 8,
  sym__forced_character_line = 9,
  sym__parenthetical_line = 10,
  sym__lyric_line = 11,
  sym__synopsis_line = 12,
  sym__section_marker = 13,
  sym__page_break_line = 14,
  sym__forced_action_line = 15,
  sym__title_key = 16,
  sym__any_line = 17,
  sym__blank = 18,
  sym_screenplay = 19,
  sym__block = 20,
  sym_title_page = 21,
  sym_title_entry = 22,
  sym_dialogue = 23,
  sym_character = 24,
  sym_parenthetical = 25,
  sym_lyric = 26,
  sym_scene_heading = 27,
  sym_transition = 28,
  sym_centered = 29,
  sym_synopsis = 30,
  sym_section = 31,
  sym_page_break = 32,
  sym_action = 33,
  aux_sym_screenplay_repeat1 = 34,
  aux_sym_screenplay_repeat2 = 35,
  aux_sym_title_page_repeat1 = 36,
  aux_sym_title_entry_repeat1 = 37,
  aux_sym_dialogue_repeat1 = 38,
  aux_sym_lyric_repeat1 = 39,
  aux_sym_centered_repeat1 = 40,
  aux_sym_action_repeat1 = 41,
  alias_sym_dialogue_line = 42,
  alias_sym_section_title = 43,
  alias_sym_title_value = 44,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_note] = "note",
  [sym_boneyard] = "boneyard",
  [sym__scene_line] = "_scene_line",
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
  [sym_transition] = "transition",
  [sym_centered] = "centered",
  [sym_synopsis] = "synopsis",
  [sym_section] = "section",
  [sym_page_break] = "page_break",
  [sym_action] = "action",
  [aux_sym_screenplay_repeat1] = "screenplay_repeat1",
  [aux_sym_screenplay_repeat2] = "screenplay_repeat2",
  [aux_sym_title_page_repeat1] = "title_page_repeat1",
  [aux_sym_title_entry_repeat1] = "title_entry_repeat1",
  [aux_sym_dialogue_repeat1] = "dialogue_repeat1",
  [aux_sym_lyric_repeat1] = "lyric_repeat1",
  [aux_sym_centered_repeat1] = "centered_repeat1",
  [aux_sym_action_repeat1] = "action_repeat1",
  [alias_sym_dialogue_line] = "dialogue_line",
  [alias_sym_section_title] = "section_title",
  [alias_sym_title_value] = "title_value",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_note] = sym_note,
  [sym_boneyard] = sym_boneyard,
  [sym__scene_line] = sym__scene_line,
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
  [sym_transition] = sym_transition,
  [sym_centered] = sym_centered,
  [sym_synopsis] = sym_synopsis,
  [sym_section] = sym_section,
  [sym_page_break] = sym_page_break,
  [sym_action] = sym_action,
  [aux_sym_screenplay_repeat1] = aux_sym_screenplay_repeat1,
  [aux_sym_screenplay_repeat2] = aux_sym_screenplay_repeat2,
  [aux_sym_title_page_repeat1] = aux_sym_title_page_repeat1,
  [aux_sym_title_entry_repeat1] = aux_sym_title_entry_repeat1,
  [aux_sym_dialogue_repeat1] = aux_sym_dialogue_repeat1,
  [aux_sym_lyric_repeat1] = aux_sym_lyric_repeat1,
  [aux_sym_centered_repeat1] = aux_sym_centered_repeat1,
  [aux_sym_action_repeat1] = aux_sym_action_repeat1,
  [alias_sym_dialogue_line] = alias_sym_dialogue_line,
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
  [sym__scene_line] = {
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
  [aux_sym_centered_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_action_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_dialogue_line] = {
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
  field_marker = 3,
  field_title = 4,
  field_value = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_character] = "character",
  [field_key] = "key",
  [field_marker] = "marker",
  [field_title] = "title",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 2},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 2},
  [9] = {.index = 10, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_marker, 0},
  [1] =
    {field_marker, 0},
    {field_title, 1},
  [3] =
    {field_value, 0},
  [4] =
    {field_key, 0},
  [5] =
    {field_key, 0},
    {field_value, 1, .inherited = true},
  [7] =
    {field_character, 0},
  [8] =
    {field_key, 0},
    {field_value, 2, .inherited = true},
  [10] =
    {field_value, 0, .inherited = true},
    {field_value, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
    [1] = alias_sym_section_title,
  },
  [3] = {
    [0] = alias_sym_title_value,
  },
  [6] = {
    [0] = alias_sym_dialogue_line,
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
  [19] = 19,
  [20] = 20,
  [21] = 18,
  [22] = 19,
  [23] = 20,
  [24] = 24,
  [25] = 24,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 30,
  [34] = 29,
  [35] = 27,
  [36] = 36,
  [37] = 28,
  [38] = 26,
  [39] = 39,
  [40] = 31,
  [41] = 32,
  [42] = 42,
  [43] = 31,
  [44] = 44,
  [45] = 45,
  [46] = 32,
  [47] = 42,
  [48] = 39,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 49,
  [63] = 63,
  [64] = 64,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 91,
        '\n', 233,
        '\r', 1,
        ' ', 91,
        '!', 88,
        '#', 84,
        '(', 154,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 134,
        'C', 122,
        'D', 98,
        'E', 132,
        'I', 92,
        'N', 127,
        'R', 105,
        'S', 125,
        'T', 117,
        '[', 170,
        'a', 220,
        'c', 200,
        'd', 175,
        'e', 209,
        'i', 164,
        'n', 204,
        'r', 182,
        's', 202,
        't', 195,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(233);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead == '[') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '\n', 233,
        '\r', 1,
        '/', 16,
        '>', 62,
        '[', 22,
        '~', 73,
        '\t', 3,
        ' ', 3,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(90);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(13);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == ']') ADVANCE(24);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(67);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(70);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(232);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(64);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(58);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == 'T') ADVANCE(20);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(21);
      END_STATE();
    case 18:
      if (lookahead == '<') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == '<') ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == 'O') ADVANCE(17);
      if (lookahead == 'T') ADVANCE(20);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == 'T') ADVANCE(20);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '[') ADVANCE(23);
      END_STATE();
    case 23:
      if (lookahead == ']') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == ']') ADVANCE(34);
      END_STATE();
    case 25:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 152,
        '\n', 233,
        '\r', 1,
        ' ', 152,
        '!', 88,
        '#', 84,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 134,
        'C', 122,
        'D', 98,
        'E', 132,
        'I', 92,
        'N', 127,
        'R', 105,
        'S', 125,
        'T', 117,
        '[', 170,
        'a', 220,
        'c', 200,
        'd', 175,
        'e', 209,
        'i', 164,
        'n', 204,
        'r', 182,
        's', 202,
        't', 195,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 26:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 153,
        '\n', 233,
        '\r', 1,
        ' ', 153,
        '!', 88,
        '#', 84,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'E', 132,
        'I', 92,
        '[', 170,
        'e', 209,
        'i', 164,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 27:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\n', 233,
        '\r', 1,
        '(', 154,
        '/', 161,
        '>', 62,
        '[', 170,
        '~', 73,
        '\t', 158,
        ' ', 158,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 28:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\n', 233,
        '\r', 1,
        '(', 154,
        '/', 161,
        '[', 170,
        '~', 73,
        '\t', 159,
        ' ', 159,
      );
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 29:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(162);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 30:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '[') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(163);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 31:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead == '[') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 32:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\n', 233,
        '\r', 1,
        '/', 16,
        '>', 62,
        '[', 22,
        '~', 73,
        '\t', 3,
        ' ', 3,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(21);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_boneyard);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__scene_line);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__scene_line);
      ADVANCE_MAP(
        '\t', 45,
        '\n', 36,
        '\r', 50,
        ' ', 40,
        '(', 42,
        '/', 47,
        'T', 39,
        '^', 45,
        '\'', 41,
        '-', 41,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(40);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__scene_line);
      ADVANCE_MAP(
        '\t', 45,
        '\n', 36,
        '\r', 50,
        ' ', 40,
        '(', 42,
        ':', 45,
        'T', 39,
        '^', 45,
        '\'', 41,
        '-', 41,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(40);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__scene_line);
      ADVANCE_MAP(
        '\t', 45,
        '\n', 36,
        '\r', 50,
        ' ', 40,
        '(', 42,
        'O', 38,
        'T', 39,
        '^', 45,
        '\'', 41,
        '-', 41,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(40);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__scene_line);
      ADVANCE_MAP(
        '\t', 45,
        '\n', 36,
        '\r', 50,
        ' ', 40,
        '(', 42,
        'T', 39,
        '^', 45,
        '\'', 41,
        '-', 41,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(40);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\t') ADVANCE(45);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == ' ') ADVANCE(41);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == '^') ADVANCE(45);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(41);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(43);
      if (lookahead != 0) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == '^') ADVANCE(45);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(43);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == '/') ADVANCE(47);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(50);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(49);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(46);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(48);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__scene_line);
      if (lookahead == '\n') ADVANCE(36);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__forced_scene_line);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\t') ADVANCE(55);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead == ' ') ADVANCE(52);
      if (lookahead == '(') ADVANCE(53);
      if (lookahead == '^') ADVANCE(55);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(52);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead == '(') ADVANCE(57);
      if (lookahead == ')') ADVANCE(54);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead == '(') ADVANCE(53);
      if (lookahead == '^') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(54);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__forced_scene_line);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(57);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__transition_line);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__forced_transition_line);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(59);
      if (lookahead == '\r') ADVANCE(61);
      if (lookahead == '<') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0) ADVANCE(61);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(59);
      if (lookahead == '\r') ADVANCE(61);
      if (lookahead == '<') ADVANCE(65);
      if (lookahead != 0) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(59);
      if (lookahead == '\r') ADVANCE(62);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym__forced_transition_line);
      if (lookahead == '\n') ADVANCE(64);
      if (lookahead == '\r') ADVANCE(62);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym__centered_line);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(64);
      if (lookahead == '\r') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__centered_line);
      if (lookahead == '\n') ADVANCE(64);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym__character_line);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__forced_character_line);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym__forced_character_line);
      if (lookahead == '\n') ADVANCE(68);
      if (lookahead == '\r') ADVANCE(69);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym__parenthetical_line);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__parenthetical_line);
      if (lookahead == '\n') ADVANCE(70);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym__lyric_line);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym__lyric_line);
      if (lookahead == '\n') ADVANCE(72);
      if (lookahead == '\r') ADVANCE(73);
      if (lookahead != 0) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym__synopsis_line);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(74);
      if (lookahead == '\r') ADVANCE(77);
      if (lookahead == '=') ADVANCE(86);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(74);
      if (lookahead == '\r') ADVANCE(77);
      if (lookahead == '=') ADVANCE(75);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(74);
      if (lookahead == '\r') ADVANCE(77);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym__synopsis_line);
      if (lookahead == '\n') ADVANCE(85);
      if (lookahead == '\r') ADVANCE(77);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__section_marker);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(79);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(80);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(81);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(82);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym__section_marker);
      if (lookahead == '#') ADVANCE(83);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym__page_break_line);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__page_break_line);
      if (lookahead == '\n') ADVANCE(85);
      if (lookahead == '\r') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__forced_action_line);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(87);
      if (lookahead == '\r') ADVANCE(88);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__title_key);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__any_line);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 91,
        '\n', 90,
        '\r', 4,
        ' ', 91,
        '!', 88,
        '#', 84,
        '(', 154,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 134,
        'C', 122,
        'D', 98,
        'E', 132,
        'I', 92,
        'N', 127,
        'R', 105,
        'S', 125,
        'T', 117,
        '[', 170,
        'a', 220,
        'c', 200,
        'd', 175,
        'e', 209,
        'i', 164,
        'n', 204,
        'r', 182,
        's', 202,
        't', 195,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        '/', 184,
        'N', 142,
        'T', 123,
        '^', 228,
        'n', 213,
        '\'', 148,
        '-', 148,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        ':', 89,
        'O', 96,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        ':', 89,
        'S', 95,
        'T', 123,
        '^', 228,
        's', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        ':', 89,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        ':', 231,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'A', 110,
        'T', 123,
        '^', 228,
        'a', 188,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'A', 140,
        'R', 97,
        'T', 123,
        '^', 228,
        'a', 218,
        'r', 174,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'A', 140,
        'T', 123,
        '^', 228,
        'a', 218,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'A', 102,
        'O', 96,
        'T', 123,
        '^', 228,
        'a', 179,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'C', 109,
        'T', 123,
        '^', 228,
        'c', 185,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'C', 145,
        'T', 123,
        '^', 228,
        'c', 215,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'D', 99,
        'T', 123,
        '^', 228,
        'd', 176,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'D', 118,
        'T', 123,
        '^', 228,
        'd', 196,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'E', 136,
        'T', 123,
        '^', 228,
        'e', 222,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'E', 104,
        'T', 123,
        '^', 228,
        'e', 181,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'E', 131,
        'O', 96,
        'T', 123,
        '^', 228,
        'e', 208,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'E', 95,
        'O', 96,
        'T', 123,
        '^', 228,
        'e', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'E', 95,
        'T', 123,
        '^', 228,
        'e', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'F', 146,
        'T', 123,
        '^', 228,
        'f', 216,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'G', 113,
        'T', 123,
        '^', 228,
        'g', 191,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'H', 126,
        'O', 96,
        'T', 123,
        '^', 228,
        'h', 203,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'H', 145,
        'T', 123,
        '^', 228,
        'h', 215,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'I', 111,
        'T', 123,
        '^', 228,
        'i', 189,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'I', 133,
        'T', 123,
        '^', 228,
        'i', 210,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'I', 124,
        'T', 123,
        '^', 228,
        'i', 201,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'I', 143,
        'T', 123,
        '^', 228,
        'i', 214,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'I', 145,
        'T', 123,
        '^', 228,
        'i', 215,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'L', 109,
        'O', 96,
        'T', 123,
        '^', 228,
        'l', 185,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'N', 95,
        'T', 123,
        '^', 228,
        'n', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'N', 144,
        'P', 137,
        'T', 123,
        '^', 228,
        'n', 217,
        'p', 224,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 121,
        'R', 106,
        'T', 123,
        '^', 228,
        'o', 199,
        'r', 183,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 96,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 120,
        'T', 123,
        '^', 228,
        'o', 198,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 135,
        'T', 123,
        '^', 228,
        'o', 221,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 129,
        'T', 123,
        '^', 228,
        'o', 206,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'O', 147,
        'T', 123,
        '^', 228,
        'o', 219,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'R', 101,
        'T', 123,
        '^', 228,
        'r', 178,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'R', 94,
        'T', 123,
        '^', 228,
        'r', 165,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'R', 114,
        'T', 123,
        '^', 228,
        'r', 192,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'S', 95,
        'T', 123,
        '^', 228,
        's', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'S', 141,
        'T', 123,
        'X', 141,
        '^', 228,
        's', 212,
        'x', 212,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'S', 116,
        'T', 123,
        '^', 228,
        's', 194,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 123,
        'U', 139,
        '^', 228,
        'u', 211,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 123,
        'U', 128,
        '^', 228,
        'u', 205,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 123,
        'V', 115,
        '^', 228,
        'v', 193,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 123,
        'Y', 130,
        '^', 228,
        'y', 207,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 112,
        '^', 228,
        't', 190,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 108,
        '^', 228,
        't', 185,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 149,
        '^', 228,
        't', 173,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 150,
        '^', 228,
        't', 156,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 119,
        '^', 228,
        't', 197,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 100,
        '^', 228,
        't', 177,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 93,
        '^', 228,
        't', 166,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 151,
        '^', 228,
        't', 157,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 138,
        '(', 160,
        'T', 107,
        '^', 228,
        't', 186,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\t') ADVANCE(228);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == ' ') ADVANCE(148);
      if (lookahead == '(') ADVANCE(160);
      if (lookahead == '^') ADVANCE(228);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(148);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 40,
        '(', 160,
        '.', 40,
        'O', 96,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 40,
        '(', 160,
        '.', 37,
        '/', 187,
        'O', 96,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 228,
        '\n', 67,
        '\r', 7,
        ' ', 103,
        '(', 160,
        'O', 96,
        'T', 123,
        '^', 228,
        '\'', 148,
        '-', 148,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 152,
        '\n', 90,
        '\r', 4,
        ' ', 152,
        '!', 88,
        '#', 84,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 134,
        'C', 122,
        'D', 98,
        'E', 132,
        'I', 92,
        'N', 127,
        'R', 105,
        'S', 125,
        'T', 117,
        '[', 170,
        'a', 220,
        'c', 200,
        'd', 175,
        'e', 209,
        'i', 164,
        'n', 204,
        'r', 182,
        's', 202,
        't', 195,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 153,
        '\n', 90,
        '\r', 4,
        ' ', 153,
        '!', 88,
        '#', 84,
        '.', 172,
        '/', 161,
        '=', 76,
        '>', 60,
        '@', 69,
        'E', 132,
        'I', 92,
        '[', 170,
        'e', 209,
        'i', 164,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(138);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '(') ADVANCE(226);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0) ADVANCE(154);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == ']') ADVANCE(171);
      if (lookahead != 0) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(50);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ') ADVANCE(180);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 90,
        '\r', 4,
        '(', 154,
        '/', 161,
        '>', 62,
        '[', 170,
        '~', 73,
        '\t', 158,
        ' ', 158,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 90,
        '\r', 4,
        '(', 154,
        '/', 161,
        '[', 170,
        '~', 73,
        '\t', 159,
        ' ', 159,
      );
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '(') ADVANCE(226);
      if (lookahead == ')') ADVANCE(227);
      if (lookahead != 0) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '*') ADVANCE(230);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(162);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '[') ADVANCE(170);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(163);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '/') ADVANCE(184);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(213);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(89);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(166);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(89);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ':') ADVANCE(231);
      if (lookahead == 'T') ADVANCE(168);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(167);
      if (lookahead == 'T') ADVANCE(168);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(168);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '[') ADVANCE(155);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ']') ADVANCE(34);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(225);
      if (('\t' <= lookahead && lookahead <= '\f')) ADVANCE(226);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(50);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(188);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(218);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(174);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(218);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(179);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(185);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(215);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(176);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(196);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(222);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(181);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(173);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(166);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(223);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(216);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(191);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(203);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(215);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(189);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(210);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(201);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(214);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(215);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(185);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(166);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(217);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(224);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(199);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(183);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(198);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(221);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(206);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(219);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(178);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(165);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(192);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(166);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(212);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(212);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(194);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(190);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(173);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(156);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(197);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(166);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(157);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(177);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(185);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(186);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(211);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(205);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(193);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(212);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(207);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(225);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(148);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == '(') ADVANCE(160);
      if (lookahead == '^') ADVANCE(228);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(227);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(228);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(232);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '*') ADVANCE(229);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead != 0) ADVANCE(230);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(232);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '*') ADVANCE(229);
      if (lookahead != 0) ADVANCE(230);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(231);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym__blank);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 25},
  [2] = {.lex_state = 26},
  [3] = {.lex_state = 26},
  [4] = {.lex_state = 26},
  [5] = {.lex_state = 26},
  [6] = {.lex_state = 26},
  [7] = {.lex_state = 26},
  [8] = {.lex_state = 26},
  [9] = {.lex_state = 25},
  [10] = {.lex_state = 25},
  [11] = {.lex_state = 25},
  [12] = {.lex_state = 25},
  [13] = {.lex_state = 25},
  [14] = {.lex_state = 25},
  [15] = {.lex_state = 26},
  [16] = {.lex_state = 25},
  [17] = {.lex_state = 26},
  [18] = {.lex_state = 28},
  [19] = {.lex_state = 28},
  [20] = {.lex_state = 27},
  [21] = {.lex_state = 28},
  [22] = {.lex_state = 28},
  [23] = {.lex_state = 27},
  [24] = {.lex_state = 28},
  [25] = {.lex_state = 28},
  [26] = {.lex_state = 29},
  [27] = {.lex_state = 29},
  [28] = {.lex_state = 29},
  [29] = {.lex_state = 29},
  [30] = {.lex_state = 29},
  [31] = {.lex_state = 28},
  [32] = {.lex_state = 28},
  [33] = {.lex_state = 29},
  [34] = {.lex_state = 29},
  [35] = {.lex_state = 29},
  [36] = {.lex_state = 32},
  [37] = {.lex_state = 29},
  [38] = {.lex_state = 29},
  [39] = {.lex_state = 28},
  [40] = {.lex_state = 28},
  [41] = {.lex_state = 28},
  [42] = {.lex_state = 28},
  [43] = {.lex_state = 32},
  [44] = {.lex_state = 31},
  [45] = {.lex_state = 31},
  [46] = {.lex_state = 32},
  [47] = {.lex_state = 28},
  [48] = {.lex_state = 28},
  [49] = {.lex_state = 30},
  [50] = {.lex_state = 32},
  [51] = {.lex_state = 30},
  [52] = {.lex_state = 32},
  [53] = {.lex_state = 32},
  [54] = {.lex_state = 28},
  [55] = {.lex_state = 32},
  [56] = {.lex_state = 32},
  [57] = {.lex_state = 32},
  [58] = {.lex_state = 32},
  [59] = {.lex_state = 32},
  [60] = {.lex_state = 32},
  [61] = {.lex_state = 32},
  [62] = {.lex_state = 30},
  [63] = {.lex_state = 32},
  [64] = {.lex_state = 32},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(1),
    [sym__forced_scene_line] = ACTIONS(1),
    [sym__transition_line] = ACTIONS(1),
    [sym__forced_transition_line] = ACTIONS(1),
    [sym__centered_line] = ACTIONS(1),
    [sym__character_line] = ACTIONS(1),
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
    [sym_screenplay] = STATE(64),
    [sym__block] = STATE(53),
    [sym_title_page] = STATE(2),
    [sym_title_entry] = STATE(9),
    [sym_dialogue] = STATE(53),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(53),
    [sym_scene_heading] = STATE(53),
    [sym_transition] = STATE(53),
    [sym_centered] = STATE(53),
    [sym_synopsis] = STATE(53),
    [sym_section] = STATE(53),
    [sym_page_break] = STATE(53),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat1] = STATE(3),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_title_page_repeat1] = STATE(9),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(55),
    [sym_dialogue] = STATE(55),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(55),
    [sym_scene_heading] = STATE(55),
    [sym_transition] = STATE(55),
    [sym_centered] = STATE(55),
    [sym_synopsis] = STATE(55),
    [sym_section] = STATE(55),
    [sym_page_break] = STATE(55),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat1] = STATE(4),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(55),
    [sym_dialogue] = STATE(55),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(55),
    [sym_scene_heading] = STATE(55),
    [sym_transition] = STATE(55),
    [sym_centered] = STATE(55),
    [sym_synopsis] = STATE(55),
    [sym_section] = STATE(55),
    [sym_page_break] = STATE(55),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat1] = STATE(15),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(50),
    [sym_dialogue] = STATE(50),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(50),
    [sym_scene_heading] = STATE(50),
    [sym_transition] = STATE(50),
    [sym_centered] = STATE(50),
    [sym_synopsis] = STATE(50),
    [sym_section] = STATE(50),
    [sym_page_break] = STATE(50),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat1] = STATE(15),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(50),
    [sym_dialogue] = STATE(50),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(50),
    [sym_scene_heading] = STATE(50),
    [sym_transition] = STATE(50),
    [sym_centered] = STATE(50),
    [sym_synopsis] = STATE(50),
    [sym_section] = STATE(50),
    [sym_page_break] = STATE(50),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(55),
    [sym_dialogue] = STATE(55),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(55),
    [sym_scene_heading] = STATE(55),
    [sym_transition] = STATE(55),
    [sym_centered] = STATE(55),
    [sym_synopsis] = STATE(55),
    [sym_section] = STATE(55),
    [sym_page_break] = STATE(55),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
    [sym__block] = STATE(61),
    [sym_dialogue] = STATE(61),
    [sym_character] = STATE(25),
    [sym_lyric] = STATE(61),
    [sym_scene_heading] = STATE(61),
    [sym_transition] = STATE(61),
    [sym_centered] = STATE(61),
    [sym_synopsis] = STATE(61),
    [sym_section] = STATE(61),
    [sym_page_break] = STATE(61),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(45),
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
  [8] = {
    [sym__block] = STATE(52),
    [sym_dialogue] = STATE(52),
    [sym_character] = STATE(24),
    [sym_lyric] = STATE(52),
    [sym_scene_heading] = STATE(52),
    [sym_transition] = STATE(52),
    [sym_centered] = STATE(52),
    [sym_synopsis] = STATE(52),
    [sym_section] = STATE(52),
    [sym_page_break] = STATE(52),
    [sym_action] = STATE(36),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_lyric_repeat1] = STATE(43),
    [aux_sym_centered_repeat1] = STATE(45),
    [ts_builtin_sym_end] = ACTIONS(81),
    [sym_note] = ACTIONS(3),
    [sym_boneyard] = ACTIONS(3),
    [sym__scene_line] = ACTIONS(7),
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
      sym__scene_line,
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
      sym__scene_line,
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
      sym__scene_line,
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
      sym__scene_line,
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
    ACTIONS(104), 1,
      ts_builtin_sym_end,
    ACTIONS(108), 1,
      sym__any_line,
    STATE(13), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(106), 14,
      sym__scene_line,
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
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
    STATE(13), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(113), 14,
      sym__scene_line,
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
      sym__scene_line,
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
      sym__scene_line,
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
    ACTIONS(39), 1,
      sym__blank,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(15), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(126), 13,
      sym__scene_line,
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
  [265] = 8,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    ACTIONS(130), 1,
      sym__parenthetical_line,
    ACTIONS(132), 1,
      sym__lyric_line,
    ACTIONS(134), 1,
      sym__any_line,
    ACTIONS(136), 1,
      sym__blank,
    STATE(31), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(19), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [293] = 8,
    ACTIONS(138), 1,
      ts_builtin_sym_end,
    ACTIONS(140), 1,
      sym__parenthetical_line,
    ACTIONS(143), 1,
      sym__lyric_line,
    ACTIONS(146), 1,
      sym__any_line,
    ACTIONS(149), 1,
      sym__blank,
    STATE(31), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(19), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [321] = 6,
    ACTIONS(151), 1,
      ts_builtin_sym_end,
    ACTIONS(157), 1,
      sym__any_line,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(155), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(153), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [344] = 7,
    ACTIONS(136), 1,
      sym__blank,
    ACTIONS(160), 1,
      sym__parenthetical_line,
    ACTIONS(162), 1,
      sym__lyric_line,
    ACTIONS(164), 1,
      sym__any_line,
    STATE(40), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(22), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [369] = 7,
    ACTIONS(149), 1,
      sym__blank,
    ACTIONS(166), 1,
      sym__parenthetical_line,
    ACTIONS(169), 1,
      sym__lyric_line,
    ACTIONS(172), 1,
      sym__any_line,
    STATE(40), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(22), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [394] = 5,
    ACTIONS(175), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(155), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(153), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [414] = 6,
    ACTIONS(130), 1,
      sym__parenthetical_line,
    ACTIONS(132), 1,
      sym__lyric_line,
    ACTIONS(134), 1,
      sym__any_line,
    STATE(31), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(18), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [436] = 6,
    ACTIONS(160), 1,
      sym__parenthetical_line,
    ACTIONS(162), 1,
      sym__lyric_line,
    ACTIONS(164), 1,
      sym__any_line,
    STATE(40), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(21), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [458] = 5,
    ACTIONS(151), 1,
      ts_builtin_sym_end,
    ACTIONS(178), 1,
      sym__any_line,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [477] = 6,
    ACTIONS(178), 1,
      sym__any_line,
    ACTIONS(180), 1,
      ts_builtin_sym_end,
    ACTIONS(183), 1,
      sym__blank,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [498] = 5,
    ACTIONS(186), 1,
      ts_builtin_sym_end,
    ACTIONS(190), 1,
      sym__any_line,
    STATE(30), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(188), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [517] = 6,
    ACTIONS(178), 1,
      sym__any_line,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(195), 1,
      sym__blank,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [538] = 5,
    ACTIONS(198), 1,
      ts_builtin_sym_end,
    ACTIONS(202), 1,
      sym__any_line,
    STATE(30), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(200), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [557] = 5,
    ACTIONS(205), 1,
      ts_builtin_sym_end,
    ACTIONS(209), 1,
      sym__lyric_line,
    STATE(32), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(207), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [576] = 5,
    ACTIONS(211), 1,
      ts_builtin_sym_end,
    ACTIONS(215), 1,
      sym__lyric_line,
    STATE(32), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(213), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [595] = 4,
    ACTIONS(218), 1,
      sym__any_line,
    STATE(33), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(200), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [611] = 5,
    ACTIONS(195), 1,
      sym__blank,
    ACTIONS(221), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [629] = 5,
    ACTIONS(183), 1,
      sym__blank,
    ACTIONS(221), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [647] = 4,
    STATE(59), 1,
      sym_transition,
    ACTIONS(223), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(227), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [663] = 4,
    ACTIONS(229), 1,
      sym__any_line,
    STATE(33), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(188), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [679] = 4,
    ACTIONS(221), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(153), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [695] = 3,
    ACTIONS(231), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(233), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [709] = 4,
    ACTIONS(235), 1,
      sym__lyric_line,
    STATE(41), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(207), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [725] = 4,
    ACTIONS(237), 1,
      sym__lyric_line,
    STATE(41), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(213), 3,
      sym__parenthetical_line,
      sym__any_line,
      sym__blank,
  [741] = 3,
    ACTIONS(240), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(242), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [755] = 4,
    ACTIONS(244), 1,
      sym__lyric_line,
    STATE(46), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(205), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [770] = 4,
    ACTIONS(248), 1,
      sym__centered_line,
    STATE(44), 1,
      aux_sym_centered_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(246), 2,
      ts_builtin_sym_end,
      sym__blank,
  [785] = 4,
    ACTIONS(253), 1,
      sym__centered_line,
    STATE(44), 1,
      aux_sym_centered_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(251), 2,
      ts_builtin_sym_end,
      sym__blank,
  [800] = 4,
    ACTIONS(255), 1,
      sym__lyric_line,
    STATE(46), 1,
      aux_sym_lyric_repeat1,
    ACTIONS(211), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [815] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(242), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [826] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(233), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [837] = 4,
    ACTIONS(258), 1,
      ts_builtin_sym_end,
    ACTIONS(260), 1,
      sym__any_line,
    ACTIONS(262), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [851] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(264), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [865] = 4,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(266), 1,
      sym__blank,
    STATE(12), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [879] = 4,
    ACTIONS(264), 1,
      sym__blank,
    ACTIONS(268), 1,
      ts_builtin_sym_end,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [893] = 4,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(264), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [907] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(155), 3,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
  [917] = 4,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(264), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [931] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(270), 2,
      ts_builtin_sym_end,
      sym__blank,
  [940] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(272), 2,
      ts_builtin_sym_end,
      sym__blank,
  [949] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(274), 2,
      ts_builtin_sym_end,
      sym__blank,
  [958] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(276), 2,
      ts_builtin_sym_end,
      sym__blank,
  [967] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(278), 2,
      ts_builtin_sym_end,
      sym__blank,
  [976] = 3,
    ACTIONS(264), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
  [987] = 3,
    ACTIONS(260), 1,
      sym__any_line,
    ACTIONS(262), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [998] = 2,
    ACTIONS(225), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(280), 2,
      ts_builtin_sym_end,
      sym__blank,
  [1007] = 2,
    ACTIONS(282), 1,
      ts_builtin_sym_end,
    ACTIONS(225), 2,
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
  [SMALL_STATE(19)] = 293,
  [SMALL_STATE(20)] = 321,
  [SMALL_STATE(21)] = 344,
  [SMALL_STATE(22)] = 369,
  [SMALL_STATE(23)] = 394,
  [SMALL_STATE(24)] = 414,
  [SMALL_STATE(25)] = 436,
  [SMALL_STATE(26)] = 458,
  [SMALL_STATE(27)] = 477,
  [SMALL_STATE(28)] = 498,
  [SMALL_STATE(29)] = 517,
  [SMALL_STATE(30)] = 538,
  [SMALL_STATE(31)] = 557,
  [SMALL_STATE(32)] = 576,
  [SMALL_STATE(33)] = 595,
  [SMALL_STATE(34)] = 611,
  [SMALL_STATE(35)] = 629,
  [SMALL_STATE(36)] = 647,
  [SMALL_STATE(37)] = 663,
  [SMALL_STATE(38)] = 679,
  [SMALL_STATE(39)] = 695,
  [SMALL_STATE(40)] = 709,
  [SMALL_STATE(41)] = 725,
  [SMALL_STATE(42)] = 741,
  [SMALL_STATE(43)] = 755,
  [SMALL_STATE(44)] = 770,
  [SMALL_STATE(45)] = 785,
  [SMALL_STATE(46)] = 800,
  [SMALL_STATE(47)] = 815,
  [SMALL_STATE(48)] = 826,
  [SMALL_STATE(49)] = 837,
  [SMALL_STATE(50)] = 851,
  [SMALL_STATE(51)] = 865,
  [SMALL_STATE(52)] = 879,
  [SMALL_STATE(53)] = 893,
  [SMALL_STATE(54)] = 907,
  [SMALL_STATE(55)] = 917,
  [SMALL_STATE(56)] = 931,
  [SMALL_STATE(57)] = 940,
  [SMALL_STATE(58)] = 949,
  [SMALL_STATE(59)] = 958,
  [SMALL_STATE(60)] = 967,
  [SMALL_STATE(61)] = 976,
  [SMALL_STATE(62)] = 987,
  [SMALL_STATE(63)] = 998,
  [SMALL_STATE(64)] = 1007,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 2, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(34),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(63),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(35),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(60),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(45),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(23),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(43),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(56),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(62),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(57),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(38),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_page, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_page, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0), SHIFT_REPEAT(51),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 4),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 4),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 5),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 5),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 9),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 9),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 9), SHIFT_REPEAT(16),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 3, 0, 8),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 3, 0, 8),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [119] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 3),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 3),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialogue, 2, 2, 7),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialogue, 2, 2, 7),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [140] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [143] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [146] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character, 1, 0, 0),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(28),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [166] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [172] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [175] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(37),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [180] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [183] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 2, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [192] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [195] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [202] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lyric, 1, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_lyric, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0),
  [215] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [218] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 1, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [237] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 6),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 6),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0),
  [248] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_centered, 1, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [255] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lyric_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 1),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section, 1, 0, 1),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 4, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_synopsis, 1, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_page_break, 1, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 2),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 2, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0),
  [282] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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

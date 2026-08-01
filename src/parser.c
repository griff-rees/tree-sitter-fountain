#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 60
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 2
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 8

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
  sym__section_line = 13,
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
  aux_sym_centered_repeat1 = 39,
  aux_sym_action_repeat1 = 40,
  alias_sym_dialogue_line = 41,
  alias_sym_title_value = 42,
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
  [sym__section_line] = "_section_line",
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
  [aux_sym_centered_repeat1] = "centered_repeat1",
  [aux_sym_action_repeat1] = "action_repeat1",
  [alias_sym_dialogue_line] = "dialogue_line",
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
  [sym__section_line] = sym__section_line,
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
  [aux_sym_centered_repeat1] = aux_sym_centered_repeat1,
  [aux_sym_action_repeat1] = aux_sym_action_repeat1,
  [alias_sym_dialogue_line] = alias_sym_dialogue_line,
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
  [sym__section_line] = {
    .visible = false,
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
  [alias_sym_title_value] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_character = 1,
  field_key = 2,
  field_value = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_character] = "character",
  [field_key] = "key",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 2},
  [7] = {.index = 7, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_value, 0},
  [1] =
    {field_key, 0},
  [2] =
    {field_key, 0},
    {field_value, 1, .inherited = true},
  [4] =
    {field_character, 0},
  [5] =
    {field_key, 0},
    {field_value, 2, .inherited = true},
  [7] =
    {field_value, 0, .inherited = true},
    {field_value, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_title_value,
  },
  [4] = {
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
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 26,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 29,
  [35] = 25,
  [36] = 36,
  [37] = 28,
  [38] = 27,
  [39] = 24,
  [40] = 40,
  [41] = 33,
  [42] = 36,
  [43] = 31,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 36,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 92,
        '\n', 234,
        '\r', 1,
        ' ', 92,
        '!', 89,
        '#', 84,
        '(', 155,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 135,
        'C', 123,
        'D', 99,
        'E', 133,
        'I', 93,
        'N', 128,
        'R', 106,
        'S', 126,
        'T', 118,
        '[', 171,
        'a', 221,
        'c', 201,
        'd', 176,
        'e', 210,
        'i', 165,
        'n', 205,
        'r', 183,
        's', 203,
        't', 196,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(234);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == '[') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(164);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '>') ADVANCE(19);
      if (lookahead == '[') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(91);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == ']') ADVANCE(25);
      if (lookahead != 0) ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(67);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(70);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '*') ADVANCE(15);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(64);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(58);
      END_STATE();
    case 13:
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(15);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(15);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '*') ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == 'T') ADVANCE(21);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(22);
      END_STATE();
    case 19:
      if (lookahead == '<') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 20:
      if (lookahead == '<') ADVANCE(66);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == 'O') ADVANCE(18);
      if (lookahead == 'T') ADVANCE(21);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(22);
      END_STATE();
    case 22:
      if (lookahead == 'T') ADVANCE(21);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '[') ADVANCE(24);
      END_STATE();
    case 24:
      if (lookahead == ']') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(24);
      END_STATE();
    case 25:
      if (lookahead == ']') ADVANCE(34);
      END_STATE();
    case 26:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 153,
        '\n', 234,
        '\r', 1,
        ' ', 153,
        '!', 89,
        '#', 84,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 135,
        'C', 123,
        'D', 99,
        'E', 133,
        'I', 93,
        'N', 128,
        'R', 106,
        'S', 126,
        'T', 118,
        '[', 171,
        'a', 221,
        'c', 201,
        'd', 176,
        'e', 210,
        'i', 165,
        'n', 205,
        'r', 183,
        's', 203,
        't', 196,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 27:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\t', 154,
        '\n', 234,
        '\r', 1,
        ' ', 154,
        '!', 89,
        '#', 84,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'E', 133,
        'I', 93,
        '[', 171,
        'e', 210,
        'i', 165,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 28:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\n', 234,
        '\r', 1,
        '(', 155,
        '/', 162,
        '>', 62,
        '[', 171,
        '~', 73,
        '\t', 159,
        ' ', 159,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 29:
      if (eof) ADVANCE(33);
      ADVANCE_MAP(
        '\n', 234,
        '\r', 1,
        '(', 155,
        '/', 162,
        '[', 171,
        '~', 73,
        '\t', 160,
        ' ', 160,
      );
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 30:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(163);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 31:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '>') ADVANCE(19);
      if (lookahead == '[') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 32:
      if (eof) ADVANCE(33);
      if (lookahead == '\n') ADVANCE(234);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(22);
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
      if (lookahead == '\r') ADVANCE(11);
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
      if (lookahead == '\r') ADVANCE(9);
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
      if (lookahead == '=') ADVANCE(87);
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
      if (lookahead == '\n') ADVANCE(86);
      if (lookahead == '\r') ADVANCE(77);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__section_line);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead == '#') ADVANCE(85);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead == '#') ADVANCE(80);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead == '#') ADVANCE(81);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead == '#') ADVANCE(82);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead == '#') ADVANCE(83);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym__section_line);
      if (lookahead == '\n') ADVANCE(79);
      if (lookahead == '\r') ADVANCE(85);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym__page_break_line);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym__page_break_line);
      if (lookahead == '\n') ADVANCE(86);
      if (lookahead == '\r') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym__forced_action_line);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym__forced_action_line);
      if (lookahead == '\n') ADVANCE(88);
      if (lookahead == '\r') ADVANCE(89);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym__title_key);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym__any_line);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 92,
        '\n', 91,
        '\r', 5,
        ' ', 92,
        '!', 89,
        '#', 84,
        '(', 155,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 135,
        'C', 123,
        'D', 99,
        'E', 133,
        'I', 93,
        'N', 128,
        'R', 106,
        'S', 126,
        'T', 118,
        '[', 171,
        'a', 221,
        'c', 201,
        'd', 176,
        'e', 210,
        'i', 165,
        'n', 205,
        'r', 183,
        's', 203,
        't', 196,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        '/', 185,
        'N', 143,
        'T', 124,
        '^', 229,
        'n', 214,
        '\'', 149,
        '-', 149,
      );
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        ':', 90,
        'O', 97,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        ':', 90,
        'S', 96,
        'T', 124,
        '^', 229,
        's', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        ':', 90,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        ':', 232,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'A', 111,
        'T', 124,
        '^', 229,
        'a', 189,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'A', 141,
        'R', 98,
        'T', 124,
        '^', 229,
        'a', 219,
        'r', 175,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'A', 141,
        'T', 124,
        '^', 229,
        'a', 219,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'A', 103,
        'O', 97,
        'T', 124,
        '^', 229,
        'a', 180,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'C', 110,
        'T', 124,
        '^', 229,
        'c', 186,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'C', 146,
        'T', 124,
        '^', 229,
        'c', 216,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'D', 100,
        'T', 124,
        '^', 229,
        'd', 177,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'D', 119,
        'T', 124,
        '^', 229,
        'd', 197,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'E', 137,
        'T', 124,
        '^', 229,
        'e', 223,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'E', 105,
        'T', 124,
        '^', 229,
        'e', 182,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'E', 132,
        'O', 97,
        'T', 124,
        '^', 229,
        'e', 209,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'E', 96,
        'O', 97,
        'T', 124,
        '^', 229,
        'e', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'E', 96,
        'T', 124,
        '^', 229,
        'e', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'F', 147,
        'T', 124,
        '^', 229,
        'f', 217,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'G', 114,
        'T', 124,
        '^', 229,
        'g', 192,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'H', 127,
        'O', 97,
        'T', 124,
        '^', 229,
        'h', 204,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'H', 146,
        'T', 124,
        '^', 229,
        'h', 216,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'I', 112,
        'T', 124,
        '^', 229,
        'i', 190,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'I', 134,
        'T', 124,
        '^', 229,
        'i', 211,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'I', 125,
        'T', 124,
        '^', 229,
        'i', 202,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'I', 144,
        'T', 124,
        '^', 229,
        'i', 215,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'I', 146,
        'T', 124,
        '^', 229,
        'i', 216,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'L', 110,
        'O', 97,
        'T', 124,
        '^', 229,
        'l', 186,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'N', 96,
        'T', 124,
        '^', 229,
        'n', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'N', 145,
        'P', 138,
        'T', 124,
        '^', 229,
        'n', 218,
        'p', 225,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 122,
        'R', 107,
        'T', 124,
        '^', 229,
        'o', 200,
        'r', 184,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 97,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 121,
        'T', 124,
        '^', 229,
        'o', 199,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 136,
        'T', 124,
        '^', 229,
        'o', 222,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 130,
        'T', 124,
        '^', 229,
        'o', 207,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'O', 148,
        'T', 124,
        '^', 229,
        'o', 220,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'R', 102,
        'T', 124,
        '^', 229,
        'r', 179,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'R', 95,
        'T', 124,
        '^', 229,
        'r', 166,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'R', 115,
        'T', 124,
        '^', 229,
        'r', 193,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'S', 96,
        'T', 124,
        '^', 229,
        's', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'S', 142,
        'T', 124,
        'X', 142,
        '^', 229,
        's', 213,
        'x', 213,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'S', 117,
        'T', 124,
        '^', 229,
        's', 195,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 124,
        'U', 140,
        '^', 229,
        'u', 212,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 124,
        'U', 129,
        '^', 229,
        'u', 206,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 124,
        'V', 116,
        '^', 229,
        'v', 194,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 124,
        'Y', 131,
        '^', 229,
        'y', 208,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 113,
        '^', 229,
        't', 191,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 109,
        '^', 229,
        't', 186,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 150,
        '^', 229,
        't', 174,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 151,
        '^', 229,
        't', 157,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 120,
        '^', 229,
        't', 198,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 101,
        '^', 229,
        't', 178,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 94,
        '^', 229,
        't', 167,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 152,
        '^', 229,
        't', 158,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 139,
        '(', 161,
        'T', 108,
        '^', 229,
        't', 187,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\t') ADVANCE(229);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == ' ') ADVANCE(149);
      if (lookahead == '(') ADVANCE(161);
      if (lookahead == '^') ADVANCE(229);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(149);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 40,
        '(', 161,
        '.', 40,
        'O', 97,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 40,
        '(', 161,
        '.', 37,
        '/', 188,
        'O', 97,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 229,
        '\n', 67,
        '\r', 8,
        ' ', 104,
        '(', 161,
        'O', 97,
        'T', 124,
        '^', 229,
        '\'', 149,
        '-', 149,
      );
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 153,
        '\n', 91,
        '\r', 5,
        ' ', 153,
        '!', 89,
        '#', 84,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'A', 135,
        'C', 123,
        'D', 99,
        'E', 133,
        'I', 93,
        'N', 128,
        'R', 106,
        'S', 126,
        'T', 118,
        '[', 171,
        'a', 221,
        'c', 201,
        'd', 176,
        'e', 210,
        'i', 165,
        'n', 205,
        'r', 183,
        's', 203,
        't', 196,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('B' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\t', 154,
        '\n', 91,
        '\r', 5,
        ' ', 154,
        '!', 89,
        '#', 84,
        '.', 173,
        '/', 162,
        '=', 76,
        '>', 60,
        '@', 69,
        'E', 133,
        'I', 93,
        '[', 171,
        'e', 210,
        'i', 165,
        '~', 73,
      );
      if (lookahead == '\'' ||
          ('-' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(139);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == '(') ADVANCE(227);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead != 0) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(7);
      if (lookahead == ']') ADVANCE(172);
      if (lookahead != 0) ADVANCE(156);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ' ') ADVANCE(50);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '/') ADVANCE(188);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ' ') ADVANCE(181);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 91,
        '\r', 5,
        '(', 155,
        '/', 162,
        '>', 62,
        '[', 171,
        '~', 73,
        '\t', 159,
        ' ', 159,
      );
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym__any_line);
      ADVANCE_MAP(
        '\n', 91,
        '\r', 5,
        '(', 155,
        '/', 162,
        '[', 171,
        '~', 73,
        '\t', 160,
        ' ', 160,
      );
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '(') ADVANCE(227);
      if (lookahead == ')') ADVANCE(228);
      if (lookahead != 0) ADVANCE(161);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '*') ADVANCE(231);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == '>') ADVANCE(62);
      if (lookahead == '[') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(163);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead == '[') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(164);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '/') ADVANCE(185);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(214);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(90);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(167);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(90);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ':') ADVANCE(232);
      if (lookahead == 'T') ADVANCE(169);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O') ADVANCE(168);
      if (lookahead == 'T') ADVANCE(169);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(169);
      if (lookahead == ' ' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z')) ADVANCE(170);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == '[') ADVANCE(156);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ']') ADVANCE(34);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(226);
      if (('\t' <= lookahead && lookahead <= '\f')) ADVANCE(227);
      if (lookahead == '\'' ||
          lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(52);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ' ' ||
          lookahead == '.') ADVANCE(50);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(189);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(219);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(175);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(219);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(180);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(186);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(216);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(177);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(197);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(223);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(182);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(174);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(167);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(209);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(224);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(217);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(192);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(204);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(216);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(190);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(211);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(202);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(215);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(216);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(186);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(167);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(218);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(225);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(200);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(184);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(199);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(222);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(207);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(220);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(179);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(166);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(193);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(167);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(213);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(213);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(195);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(191);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(174);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(157);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(198);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(167);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(158);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(178);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(186);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(187);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(212);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(206);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(194);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(213);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(208);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead == ' ' ||
          lookahead == '\'' ||
          lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(149);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(91);
      if (lookahead == '\r') ADVANCE(5);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '(') ADVANCE(161);
      if (lookahead == '^') ADVANCE(229);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(228);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(67);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(229);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '*') ADVANCE(230);
      if (lookahead == '/') ADVANCE(35);
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead == '\r') ADVANCE(10);
      if (lookahead == '*') ADVANCE(230);
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(232);
      if (lookahead != 0) ADVANCE(227);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym__any_line);
      if (lookahead == '*') ADVANCE(15);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym__blank);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 26},
  [2] = {.lex_state = 27},
  [3] = {.lex_state = 27},
  [4] = {.lex_state = 27},
  [5] = {.lex_state = 27},
  [6] = {.lex_state = 27},
  [7] = {.lex_state = 27},
  [8] = {.lex_state = 27},
  [9] = {.lex_state = 26},
  [10] = {.lex_state = 26},
  [11] = {.lex_state = 26},
  [12] = {.lex_state = 26},
  [13] = {.lex_state = 26},
  [14] = {.lex_state = 26},
  [15] = {.lex_state = 26},
  [16] = {.lex_state = 27},
  [17] = {.lex_state = 27},
  [18] = {.lex_state = 28},
  [19] = {.lex_state = 29},
  [20] = {.lex_state = 29},
  [21] = {.lex_state = 28},
  [22] = {.lex_state = 29},
  [23] = {.lex_state = 29},
  [24] = {.lex_state = 30},
  [25] = {.lex_state = 30},
  [26] = {.lex_state = 29},
  [27] = {.lex_state = 30},
  [28] = {.lex_state = 30},
  [29] = {.lex_state = 30},
  [30] = {.lex_state = 29},
  [31] = {.lex_state = 29},
  [32] = {.lex_state = 32},
  [33] = {.lex_state = 29},
  [34] = {.lex_state = 30},
  [35] = {.lex_state = 30},
  [36] = {.lex_state = 29},
  [37] = {.lex_state = 30},
  [38] = {.lex_state = 30},
  [39] = {.lex_state = 30},
  [40] = {.lex_state = 31},
  [41] = {.lex_state = 29},
  [42] = {.lex_state = 29},
  [43] = {.lex_state = 29},
  [44] = {.lex_state = 31},
  [45] = {.lex_state = 29},
  [46] = {.lex_state = 32},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 32},
  [49] = {.lex_state = 32},
  [50] = {.lex_state = 32},
  [51] = {.lex_state = 32},
  [52] = {.lex_state = 32},
  [53] = {.lex_state = 32},
  [54] = {.lex_state = 32},
  [55] = {.lex_state = 32},
  [56] = {.lex_state = 32},
  [57] = {.lex_state = 32},
  [58] = {.lex_state = 32},
  [59] = {.lex_state = 32},
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
    [sym__section_line] = ACTIONS(1),
    [sym__page_break_line] = ACTIONS(1),
    [sym__forced_action_line] = ACTIONS(1),
    [sym__title_key] = ACTIONS(1),
    [sym__any_line] = ACTIONS(1),
    [sym__blank] = ACTIONS(1),
  },
  [1] = {
    [sym_screenplay] = STATE(59),
    [sym__block] = STATE(49),
    [sym_title_page] = STATE(3),
    [sym_title_entry] = STATE(9),
    [sym_dialogue] = STATE(49),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(49),
    [sym_scene_heading] = STATE(49),
    [sym_transition] = STATE(49),
    [sym_centered] = STATE(49),
    [sym_synopsis] = STATE(49),
    [sym_section] = STATE(49),
    [sym_page_break] = STATE(49),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat1] = STATE(2),
    [aux_sym_screenplay_repeat2] = STATE(5),
    [aux_sym_title_page_repeat1] = STATE(9),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__title_key] = ACTIONS(31),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(33),
  },
  [2] = {
    [sym__block] = STATE(50),
    [sym_dialogue] = STATE(50),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(50),
    [sym_scene_heading] = STATE(50),
    [sym_transition] = STATE(50),
    [sym_centered] = STATE(50),
    [sym_synopsis] = STATE(50),
    [sym_section] = STATE(50),
    [sym_page_break] = STATE(50),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat1] = STATE(17),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(37),
  },
  [3] = {
    [sym__block] = STATE(50),
    [sym_dialogue] = STATE(50),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(50),
    [sym_scene_heading] = STATE(50),
    [sym_transition] = STATE(50),
    [sym_centered] = STATE(50),
    [sym_synopsis] = STATE(50),
    [sym_section] = STATE(50),
    [sym_page_break] = STATE(50),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat1] = STATE(4),
    [aux_sym_screenplay_repeat2] = STATE(6),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(39),
  },
  [4] = {
    [sym__block] = STATE(46),
    [sym_dialogue] = STATE(46),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(46),
    [sym_scene_heading] = STATE(46),
    [sym_transition] = STATE(46),
    [sym_centered] = STATE(46),
    [sym_synopsis] = STATE(46),
    [sym_section] = STATE(46),
    [sym_page_break] = STATE(46),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat1] = STATE(17),
    [aux_sym_screenplay_repeat2] = STATE(8),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
    [sym__blank] = ACTIONS(37),
  },
  [5] = {
    [sym__block] = STATE(50),
    [sym_dialogue] = STATE(50),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(50),
    [sym_scene_heading] = STATE(50),
    [sym_transition] = STATE(50),
    [sym_centered] = STATE(50),
    [sym_synopsis] = STATE(50),
    [sym_section] = STATE(50),
    [sym_page_break] = STATE(50),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
  },
  [6] = {
    [sym__block] = STATE(46),
    [sym_dialogue] = STATE(46),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(46),
    [sym_scene_heading] = STATE(46),
    [sym_transition] = STATE(46),
    [sym_centered] = STATE(46),
    [sym_synopsis] = STATE(46),
    [sym_section] = STATE(46),
    [sym_page_break] = STATE(46),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
    [sym__page_break_line] = ACTIONS(27),
    [sym__forced_action_line] = ACTIONS(29),
    [sym__any_line] = ACTIONS(29),
  },
  [7] = {
    [sym__block] = STATE(55),
    [sym_dialogue] = STATE(55),
    [sym_character] = STATE(30),
    [sym_lyric] = STATE(55),
    [sym_scene_heading] = STATE(55),
    [sym_transition] = STATE(55),
    [sym_centered] = STATE(55),
    [sym_synopsis] = STATE(55),
    [sym_section] = STATE(55),
    [sym_page_break] = STATE(55),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(72),
    [sym__page_break_line] = ACTIONS(75),
    [sym__forced_action_line] = ACTIONS(78),
    [sym__any_line] = ACTIONS(78),
  },
  [8] = {
    [sym__block] = STATE(48),
    [sym_dialogue] = STATE(48),
    [sym_character] = STATE(26),
    [sym_lyric] = STATE(48),
    [sym_scene_heading] = STATE(48),
    [sym_transition] = STATE(48),
    [sym_centered] = STATE(48),
    [sym_synopsis] = STATE(48),
    [sym_section] = STATE(48),
    [sym_page_break] = STATE(48),
    [sym_action] = STATE(32),
    [aux_sym_screenplay_repeat2] = STATE(7),
    [aux_sym_centered_repeat1] = STATE(44),
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
    [sym__section_line] = ACTIONS(25),
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
      sym__section_line,
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
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
      sym__blank,
  [62] = 5,
    ACTIONS(94), 1,
      ts_builtin_sym_end,
    ACTIONS(98), 1,
      sym__any_line,
    STATE(13), 1,
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
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [92] = 5,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    STATE(14), 1,
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
      sym__section_line,
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
      sym__scene_line,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_line,
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
      sym__scene_line,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__blank,
  [182] = 3,
    ACTIONS(115), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(117), 15,
      sym__scene_line,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__title_key,
      sym__any_line,
      sym__blank,
  [207] = 5,
    ACTIONS(37), 1,
      sym__blank,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(119), 13,
      sym__scene_line,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
  [236] = 5,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    ACTIONS(125), 1,
      sym__blank,
    STATE(17), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(123), 13,
      sym__scene_line,
      sym__forced_scene_line,
      sym__transition_line,
      sym__forced_transition_line,
      sym__centered_line,
      sym__character_line,
      sym__forced_character_line,
      sym__lyric_line,
      sym__synopsis_line,
      sym__section_line,
      sym__page_break_line,
      sym__forced_action_line,
      sym__any_line,
  [265] = 6,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    ACTIONS(134), 1,
      sym__any_line,
    STATE(24), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(132), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(130), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [288] = 7,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
    ACTIONS(139), 1,
      sym__parenthetical_line,
    ACTIONS(141), 1,
      sym__lyric_line,
    ACTIONS(143), 1,
      sym__any_line,
    ACTIONS(145), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(20), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [313] = 7,
    ACTIONS(147), 1,
      ts_builtin_sym_end,
    ACTIONS(149), 1,
      sym__parenthetical_line,
    ACTIONS(152), 1,
      sym__lyric_line,
    ACTIONS(155), 1,
      sym__any_line,
    ACTIONS(158), 1,
      sym__blank,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(20), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [338] = 5,
    ACTIONS(160), 1,
      sym__any_line,
    STATE(39), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(132), 2,
      sym__parenthetical_line,
      sym__lyric_line,
    ACTIONS(130), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [358] = 6,
    ACTIONS(145), 1,
      sym__blank,
    ACTIONS(163), 1,
      sym__parenthetical_line,
    ACTIONS(165), 1,
      sym__lyric_line,
    ACTIONS(167), 1,
      sym__any_line,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(23), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [380] = 6,
    ACTIONS(158), 1,
      sym__blank,
    ACTIONS(169), 1,
      sym__parenthetical_line,
    ACTIONS(172), 1,
      sym__lyric_line,
    ACTIONS(175), 1,
      sym__any_line,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(23), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [402] = 5,
    ACTIONS(178), 1,
      ts_builtin_sym_end,
    ACTIONS(182), 1,
      sym__any_line,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(180), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [421] = 5,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    ACTIONS(184), 1,
      sym__any_line,
    STATE(24), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [440] = 5,
    ACTIONS(139), 1,
      sym__parenthetical_line,
    ACTIONS(141), 1,
      sym__lyric_line,
    ACTIONS(143), 1,
      sym__any_line,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(19), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [459] = 6,
    ACTIONS(184), 1,
      sym__any_line,
    ACTIONS(186), 1,
      ts_builtin_sym_end,
    ACTIONS(189), 1,
      sym__blank,
    STATE(24), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [480] = 5,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(196), 1,
      sym__any_line,
    STATE(28), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(194), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [499] = 6,
    ACTIONS(184), 1,
      sym__any_line,
    ACTIONS(199), 1,
      ts_builtin_sym_end,
    ACTIONS(202), 1,
      sym__blank,
    STATE(24), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [520] = 5,
    ACTIONS(163), 1,
      sym__parenthetical_line,
    ACTIONS(165), 1,
      sym__lyric_line,
    ACTIONS(167), 1,
      sym__any_line,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    STATE(22), 3,
      sym_parenthetical,
      sym_lyric,
      aux_sym_dialogue_repeat1,
  [539] = 3,
    ACTIONS(205), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(207), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [553] = 4,
    STATE(58), 1,
      sym_transition,
    ACTIONS(209), 2,
      ts_builtin_sym_end,
      sym__blank,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(213), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [569] = 3,
    ACTIONS(215), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(217), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [583] = 5,
    ACTIONS(202), 1,
      sym__blank,
    ACTIONS(219), 1,
      sym__any_line,
    STATE(39), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [601] = 4,
    ACTIONS(219), 1,
      sym__any_line,
    STATE(39), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [617] = 3,
    ACTIONS(221), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(223), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [631] = 4,
    ACTIONS(225), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(194), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [647] = 5,
    ACTIONS(189), 1,
      sym__blank,
    ACTIONS(219), 1,
      sym__any_line,
    STATE(39), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(130), 2,
      sym__transition_line,
      sym__forced_transition_line,
  [665] = 4,
    ACTIONS(228), 1,
      sym__any_line,
    STATE(37), 1,
      aux_sym_action_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(180), 3,
      sym__transition_line,
      sym__forced_transition_line,
      sym__blank,
  [681] = 4,
    ACTIONS(232), 1,
      sym__centered_line,
    STATE(40), 1,
      aux_sym_centered_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(230), 2,
      ts_builtin_sym_end,
      sym__blank,
  [696] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(217), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [707] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(223), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [718] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(207), 4,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
      sym__blank,
  [729] = 4,
    ACTIONS(237), 1,
      sym__centered_line,
    STATE(40), 1,
      aux_sym_centered_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(235), 2,
      ts_builtin_sym_end,
      sym__blank,
  [744] = 2,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(132), 3,
      sym__parenthetical_line,
      sym__lyric_line,
      sym__any_line,
  [754] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(239), 1,
      sym__blank,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
  [768] = 4,
    ACTIONS(98), 1,
      sym__any_line,
    ACTIONS(241), 1,
      sym__blank,
    STATE(12), 1,
      aux_sym_title_entry_repeat1,
    ACTIONS(3), 2,
      sym_note,
      sym_boneyard,
  [782] = 4,
    ACTIONS(239), 1,
      sym__blank,
    ACTIONS(243), 1,
      ts_builtin_sym_end,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
  [796] = 4,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(239), 1,
      sym__blank,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
  [810] = 4,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(239), 1,
      sym__blank,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
  [824] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(245), 2,
      ts_builtin_sym_end,
      sym__blank,
  [833] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(247), 2,
      ts_builtin_sym_end,
      sym__blank,
  [842] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(221), 2,
      ts_builtin_sym_end,
      sym__blank,
  [851] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(249), 2,
      ts_builtin_sym_end,
      sym__blank,
  [860] = 3,
    ACTIONS(239), 1,
      sym__blank,
    STATE(16), 1,
      aux_sym_screenplay_repeat1,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
  [871] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(251), 2,
      ts_builtin_sym_end,
      sym__blank,
  [880] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(253), 2,
      ts_builtin_sym_end,
      sym__blank,
  [889] = 2,
    ACTIONS(211), 2,
      sym_note,
      sym_boneyard,
    ACTIONS(255), 2,
      ts_builtin_sym_end,
      sym__blank,
  [898] = 2,
    ACTIONS(257), 1,
      ts_builtin_sym_end,
    ACTIONS(211), 2,
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
  [SMALL_STATE(16)] = 207,
  [SMALL_STATE(17)] = 236,
  [SMALL_STATE(18)] = 265,
  [SMALL_STATE(19)] = 288,
  [SMALL_STATE(20)] = 313,
  [SMALL_STATE(21)] = 338,
  [SMALL_STATE(22)] = 358,
  [SMALL_STATE(23)] = 380,
  [SMALL_STATE(24)] = 402,
  [SMALL_STATE(25)] = 421,
  [SMALL_STATE(26)] = 440,
  [SMALL_STATE(27)] = 459,
  [SMALL_STATE(28)] = 480,
  [SMALL_STATE(29)] = 499,
  [SMALL_STATE(30)] = 520,
  [SMALL_STATE(31)] = 539,
  [SMALL_STATE(32)] = 553,
  [SMALL_STATE(33)] = 569,
  [SMALL_STATE(34)] = 583,
  [SMALL_STATE(35)] = 601,
  [SMALL_STATE(36)] = 617,
  [SMALL_STATE(37)] = 631,
  [SMALL_STATE(38)] = 647,
  [SMALL_STATE(39)] = 665,
  [SMALL_STATE(40)] = 681,
  [SMALL_STATE(41)] = 696,
  [SMALL_STATE(42)] = 707,
  [SMALL_STATE(43)] = 718,
  [SMALL_STATE(44)] = 729,
  [SMALL_STATE(45)] = 744,
  [SMALL_STATE(46)] = 754,
  [SMALL_STATE(47)] = 768,
  [SMALL_STATE(48)] = 782,
  [SMALL_STATE(49)] = 796,
  [SMALL_STATE(50)] = 810,
  [SMALL_STATE(51)] = 824,
  [SMALL_STATE(52)] = 833,
  [SMALL_STATE(53)] = 842,
  [SMALL_STATE(54)] = 851,
  [SMALL_STATE(55)] = 860,
  [SMALL_STATE(56)] = 871,
  [SMALL_STATE(57)] = 880,
  [SMALL_STATE(58)] = 889,
  [SMALL_STATE(59)] = 898,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 2, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(34),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(57),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(38),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(52),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(44),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(21),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(45),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(53),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(56),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(51),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0), SHIFT_REPEAT(35),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_page, 1, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_page, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_page_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 2),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 2),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 2, 0, 3),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 2, 0, 3),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_title_entry, 3, 0, 6),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_title_entry, 3, 0, 6),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 7),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 7),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 2, 0, 7), SHIFT_REPEAT(15),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_title_entry_repeat1, 1, 0, 1),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat2, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_screenplay_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 1, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character, 1, 0, 0),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(24),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialogue, 2, 2, 5),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialogue, 2, 2, 5),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [152] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0),
  [160] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_character, 1, 0, 0), SHIFT(39),
  [163] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [165] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [167] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [172] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [175] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [186] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [189] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_transition, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [202] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_scene_heading, 1, 2, 0), REDUCE(sym_action, 1, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 4),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialogue_repeat1, 1, 0, 4),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 1, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthetical, 1, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lyric, 1, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_lyric, 1, 0, 0),
  [225] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_action_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0),
  [232] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_centered_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_centered, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_screenplay, 4, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_page_break, 1, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition, 1, 2, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_synopsis, 1, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_heading, 1, 2, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 2, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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

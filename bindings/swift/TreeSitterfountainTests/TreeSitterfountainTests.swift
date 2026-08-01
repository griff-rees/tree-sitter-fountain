import XCTest
import SwiftTreeSitter
import TreeSitterfountain

final class TreeSitterfountainTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_fountain())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading fountain grammar")
    }
}

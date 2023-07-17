#
# Makefile used to generate Flex/Bison scanner/parser combination to recognise strings of simple expressions. This
# only needs to be run if any changes have been made to:
#	1) simple_expression.yy
#   2) simple_expression.l
#

BISON=/opt/homebrew/Cellar/bison/3.8.2/bin/bison
FLEX=/opt/homebrew/Cellar/flex/2.6.4_2/bin/flex

.PHONY: all

all: parser lexer

parser: simple_expression.yy
	$(BISON) -d -v $<

lexer: simple_expression.l
	$(FLEX) --outfile=simple_expression.yy.cc $<


clean:
	rm -rf location.hh
	rm -rf position.hh
	rm -rf simple_expression.output
	rm -rf simple_expression.tab.cc
	rm -rf simple_expression.tab.hh
	rm -rf simple_expression.yy.cc
	rm -rf stack.hh

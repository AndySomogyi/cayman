/*
 * ASTNode.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: andy
 */

#include "AstNode.h"
#include "AstVisitor.h"
#include "py_parser.hh"


namespace py
{

AstNodeSeq* AstNodeSeq::Add(const location& loc, AstNode* seq, AstNode* node)
{
	AstNodeSeq *nodes = NULL;
	if (seq)
	{
		nodes = dynamic_cast<AstNodeSeq*>(seq);

		if (!nodes) {
			throw syntax_error(location(), "seq must be NULL or an existing AstNodeSeq");
		}
	}
	else
	{
		nodes = new AstNodeSeq(loc);
	}

    if (node)
    {
        nodes->seq.push_back(node);
    }
	return nodes;
}

Name::Name(class Ast* ast, const location& loc, const char* begin,
           const char* end) :
    AstNode(ast, loc, ATOMIC), id(begin, end), ctx(UnknownCtx)
{
    // TODO verify non-dotted name
    ids.push_back(id);
}

Num::Num(class Ast* ast, const location& loc, const char* begin,
         const char* end) :
    AstNode(ast, loc, ATOMIC)
{
	type = Double;

	// TODO, horribly inefficient
	doubleValue = ::atof(std::string(begin, end).c_str());
}

static void MakeId(const std::vector<std::string> &ids, std::string &id)
{
    id.clear();
    for (std::vector<std::string>::const_iterator i = ids.begin(); i != ids.end(); ++i)
    {
        id += *i;
        
        if (i + 1 < ids.end()) {
            id += ".";
        }
    }
}
    
void Name::AppendName(AstNode *name)
{
    Name *nm = dynamic_cast<Name*>(name);
    if (nm == NULL) {
        throw syntax_error(loc, "can not append a name with a non-name");
    }
    
    ids.insert(ids.end(), nm->ids.begin(), nm->ids.end());
    MakeId(ids, id);
}
    
void Name::PrependName(AstNode *name)
{
    assert(0);
}

int Name::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Num::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Str::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Module::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Tuple::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}

int Starred::Accept(class AstVisitor* v)
{
	return v->Visit(this);
}




} /* namespace py */


namespace std
{

ostream& operator<<(ostream& os, const py::AstNode& node)
{
	node.Print(os);
	return os;
}

ostream& operator<<(ostream& os, const py::AstNode* node)
{
	if (node)
	{
		node->Print(os);
	}
	else
	{
		os << "AstNode";
	}
	return os;
}

}



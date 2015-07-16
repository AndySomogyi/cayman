/*
 * AstCodegen.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: andy
 */

#include <AstCodegen.h>

llvm::Function* IRGenContext::GetPrototype(const std::string& name)
{
	if (llvm::Function *ExistingProto = module->getFunction(name))
		return ExistingProto;
	if (FunctionAST *ast = jctx.GetFunctionAST(name))
		return ast->PrototypeIRGen(*this);
	return nullptr;
}

/*
 * llvm_test1.h
 *
 *  Created on: Jun 29, 2015
 *      Author: andy
 */

#ifndef PYCALC_SRC_LLVM_TEST1_H_
#define PYCALC_SRC_LLVM_TEST1_H_

int llvm_test1_main(int argc, const char** argv);

int llvm_orc_lazy_irgen(int argv, const char** argc);
int llvm_orc_lazy_codegen(int argc, const char** argv);
int llvm_orc_initial(int argc, const char** argv);
int llvm_orc_fully_lazy(int argc, const char** argv);

#endif /* PYCALC_SRC_LLVM_TEST1_H_ */

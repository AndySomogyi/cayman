function(prepend var)
  set(listVar "")
  foreach(f ${ARGN})
                           
    list(APPEND listVar "${CMAKE_CURRENT_SOURCE_DIR}/${f}")
  endforeach(f)
  set(${var} "${listVar}" PARENT_SCOPE)
endfunction(prepend)

set (_PUBLIC_HEADERS
  ca_abstract.h
  ca_import.h
  ca_object.h
  ca_port.h
  ca_runtime.h
  ca_string.h
  ca_tupleobject.h
  ca_number.h
  ca_type.h
  ca_callable.h
  ca_callable.h
  ca_eval.h
  ca_int.h
  ca_float.h
  ca_ast.h
  cayman.h
  )

message("_PUBLIC_HEADERS: ${_PUBLIC_HEADERS}")

prepend(PUBLIC_HEADERS  ${_PUBLIC_HEADERS})

set(CAYMAN_PUBLIC_HEADERS ${PUBLIC_HEADERS} PARENT_SCOPE)



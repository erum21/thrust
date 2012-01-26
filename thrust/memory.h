/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file memory.h
 *  \brief Abstractions for Thrust's memory model.
 */

#include <thrust/detail/config.h>

#include <thrust/detail/type_traits/pointer_traits.h>
#include <thrust/detail/pointer.h>
#include <thrust/detail/reference.h>
#include <thrust/detail/raw_pointer_cast.h>
#include <thrust/detail/raw_reference_cast.h>

// XXX TODO: document thrust::pointer & thrust::reference & thrust::raw_reference_cast

namespace thrust
{

/*! \addtogroup memory_management_functions Memory Management Functions
 *  \ingroup memory_management
 *  \{
 */

/*! \p raw_pointer_cast creates a "raw" pointer from a pointer-like type,
 *  simply returning the wrapped pointer, should it exist.
 *
 *  \param ptr The pointer of interest.
 *  \return <tt>ptr.get()</tt>, if the expression is well formed; <tt>ptr</tt>, otherwise.
 */
template<typename Pointer>
__host__ __device__
inline typename thrust::detail::pointer_traits<Pointer>::raw_pointer
  raw_pointer_cast(const Pointer &ptr);

/*! \}
 */

} // end thrust

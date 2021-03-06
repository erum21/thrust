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


/*! \file mismatch.inl
 *  \brief Inline file for mismatch.h
 */


#include <thrust/detail/config.h>
#include <thrust/mismatch.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/generic/mismatch.h>
#include <thrust/system/detail/adl/mismatch.h>

namespace thrust
{


template<typename System, typename InputIterator1, typename InputIterator2>
thrust::pair<InputIterator1, InputIterator2> mismatch(thrust::detail::dispatchable_base<System> &system,
                                                      InputIterator1 first1,
                                                      InputIterator1 last1,
                                                      InputIterator2 first2)
{
  using thrust::system::detail::generic::mismatch;
  return mismatch(system.derived(), first1, last1, first2);
} // end mismatch()


template<typename System, typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
thrust::pair<InputIterator1, InputIterator2> mismatch(thrust::detail::dispatchable_base<System> &system,
                                                      InputIterator1 first1,
                                                      InputIterator1 last1,
                                                      InputIterator2 first2,
                                                      BinaryPredicate pred)
{
  using thrust::system::detail::generic::mismatch;
  return mismatch(system.derived(), first1, last1, first2, pred);
} // end mismatch()


namespace detail
{


template<typename System, typename InputIterator1, typename InputIterator2>
  thrust::pair<InputIterator1, InputIterator2>
    strip_const_mismatch(const System &system,
                         InputIterator1 first1,
                         InputIterator1 last1,
                         InputIterator2 first2)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::mismatch(non_const_system, first1, last1, first2);
} // end mismatch()


template<typename System, typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
  thrust::pair<InputIterator1, InputIterator2>
    strip_const_mismatch(const System &system,
                         InputIterator1 first1,
                         InputIterator1 last1,
                         InputIterator2 first2,
                         BinaryPredicate pred)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::mismatch(non_const_system, first1, last1, first2, pred);
} // end mismatch()


} // end detail


template <typename InputIterator1, typename InputIterator2>
thrust::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1,
                                                      InputIterator1 last1,
                                                      InputIterator2 first2)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<InputIterator1>::type System1;
  typedef typename thrust::iterator_system<InputIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_mismatch(select_system(system1,system2), first1, last1, first2);
} // end mismatch()


template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
thrust::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1,
                                                      InputIterator1 last1,
                                                      InputIterator2 first2,
                                                      BinaryPredicate pred)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<InputIterator1>::type System1;
  typedef typename thrust::iterator_system<InputIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_mismatch(select_system(system1,system2), first1, last1, first2, pred);
} // end mismatch()


} // end namespace thrust


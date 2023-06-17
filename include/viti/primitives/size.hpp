//==============================================================================
// The MIT License (MIT)
//
// Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//==============================================================================

#ifndef VITI_PRIMITIVES_SIZE_HPP
#define VITI_PRIMITIVES_SIZE_HPP

#include <ostream>
#include <string>

#include <viti/concepts.hpp>

namespace viti::primitives {
template <concepts::integral_or_floating_point Type>
struct size {
  Type width;
  Type height;

  constexpr friend auto operator==(size<Type> const& lhs, size<Type> const& rhs)
      -> bool = default;
};

template <concepts::integral_or_floating_point Type>
constexpr auto to_string(primitives::size<Type>& size) -> std::string {
  return {"(" + std::to_string(size.width) + ", " +
          std::to_string(size.height) + ")"};
}

template <concepts::integral_or_floating_point Type>
constexpr auto operator<<(std::ostream& stream, primitives::size<Type>& size)
    -> std::ostream& {
  stream << to_string(size);
  return stream;
}
} // namespace viti::primitives

#endif // VITI_PRIMITIVES_SIZE_HPP
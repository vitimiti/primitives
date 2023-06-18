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

#ifndef VITI_PRIMITIVES_RECTANGLE_HPP
#define VITI_PRIMITIVES_RECTANGLE_HPP

#include <cmath>
#include <limits>
#include <ostream>
#include <string>

#include <viti/concepts.hpp>

#include "viti/primitives/point.hpp"
#include "viti/primitives/size.hpp"

namespace viti::primitives {
template <concepts::integral_or_floating_point Type>
struct rectangle {
  primitives::point<Type> point;
  primitives::size<Type>  size;

  constexpr friend auto operator==(rectangle<Type> const& lhs,
                                   rectangle<Type> const& rhs)
      -> bool = default;
};

template <concepts::integral_or_floating_point Type>
[[nodiscard]] constexpr auto
to_string(primitives::rectangle<Type> const& rectangle) -> std::string {
  return {"(" + std::to_string(rectangle.point) + ", " +
          std::to_string(rectangle.size) + ")"};
}

template <concepts::integral_or_floating_point Type>
[[nodiscard]] constexpr auto
is_empty(primitives::rectangle<Type> const& rectangle) -> bool {
  return rectangle.size.width <= 0 || rectangle.size.height <= 0;
}

template <concepts::integral_or_floating_point Type>
constexpr auto operator<<(std::ostream&                stream,
                          primitives::rectangle<Type>& rectangle)
    -> std::ostream& {
  stream << to_string(rectangle);
  return stream;
}
} // namespace viti::primitives

#endif // VITI_PRIMITIVES_RECTANGLE_HPP
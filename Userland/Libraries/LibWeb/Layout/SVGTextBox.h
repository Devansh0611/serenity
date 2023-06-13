/*
 * Copyright (c) 2023, Aliaksandr Kalenik <kalenik.aliaksandr@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Optional.h>
#include <LibWeb/Layout/SVGGraphicsBox.h>
#include <LibWeb/SVG/SVGTextContentElement.h>

namespace Web::Layout {

class SVGTextBox final : public SVGGraphicsBox {
    JS_CELL(SVGTextBox, SVGGraphicsBox);

public:
    SVGTextBox(DOM::Document&, SVG::SVGTextContentElement&, NonnullRefPtr<CSS::StyleProperties>);
    virtual ~SVGTextBox() override = default;

    SVG::SVGTextContentElement& dom_node() { return static_cast<SVG::SVGTextContentElement&>(SVGGraphicsBox::dom_node()); }
    SVG::SVGTextContentElement const& dom_node() const { return static_cast<SVG::SVGTextContentElement const&>(SVGGraphicsBox::dom_node()); }

    Optional<Gfx::AffineTransform> layout_transform() const;

    virtual JS::GCPtr<Painting::Paintable> create_paintable() const override;

private:
    CSSPixelPoint viewbox_origin() const;
};

}
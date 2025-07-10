void __thiscall vostok::animation::linear_interpolator::accept(
        vostok::animation::linear_interpolator *this,
        vostok::animation::interpolator_visitor *visitor)
{
  visitor->visit(visitor, this);
}

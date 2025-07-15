void __thiscall vostok::animation::linear_interpolator::accept(
        vostok::animation::linear_interpolator *this,
        vostok::animation::interpolator_visitor *visitor)
{
  visitor->visit(visitor, this);
}


void __thiscall vostok::animation::linear_interpolator::accept(
        vostok::animation::linear_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::base_interpolator *interpolator)
{
  interpolator->visit(interpolator, dispatcher, this);
}

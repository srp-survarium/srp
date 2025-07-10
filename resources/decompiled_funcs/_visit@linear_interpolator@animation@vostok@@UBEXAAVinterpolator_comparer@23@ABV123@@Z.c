void __thiscall vostok::animation::linear_interpolator::visit(
        vostok::animation::linear_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::linear_interpolator *interpolator)
{
  vostok::animation::interpolator_comparer::dispatch(dispatcher, interpolator, this);
}

void __thiscall vostok::animation::instant_interpolator::accept(
        vostok::animation::instant_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::base_interpolator *interpolator)
{
  interpolator->visit(interpolator, dispatcher, this);
}

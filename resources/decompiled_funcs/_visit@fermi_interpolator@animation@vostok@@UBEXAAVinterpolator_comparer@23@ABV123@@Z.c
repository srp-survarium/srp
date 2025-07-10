void __thiscall vostok::animation::fermi_interpolator::visit(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::fermi_interpolator *interpolator)
{
  vostok::animation::interpolator_comparer::dispatch(interpolator, this, dispatcher);
}

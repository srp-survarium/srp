void __thiscall vostok::animation::fermi_interpolator::visit(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::linear_interpolator *interpolator)
{
  dispatcher->result = less;
}

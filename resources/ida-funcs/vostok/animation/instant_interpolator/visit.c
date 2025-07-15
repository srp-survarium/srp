void __thiscall vostok::animation::instant_interpolator::visit(
        vostok::animation::instant_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::instant_interpolator *interpolator)
{
  dispatcher->result = equal;
}


void __thiscall vostok::animation::instant_interpolator::visit(
        vostok::animation::instant_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::fermi_interpolator *interpolator)
{
  dispatcher->result = more;
}


void __thiscall vostok::animation::instant_interpolator::visit(
        vostok::animation::instant_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::linear_interpolator *interpolator)
{
  dispatcher->result = more;
}

void __thiscall vostok::animation::fermi_interpolator::accept(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::interpolator_visitor *visitor)
{
  visitor->visit(visitor, this);
}

void __thiscall vostok::animation::instant_interpolator::accept(
        vostok::animation::instant_interpolator *this,
        vostok::animation::interpolator_visitor *visitor)
{
  visitor->visit(visitor, this);
}

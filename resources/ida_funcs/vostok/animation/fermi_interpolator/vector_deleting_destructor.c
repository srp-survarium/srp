vostok::animation::fermi_interpolator *__thiscall vostok::animation::fermi_interpolator::`vector deleting destructor'(
        vostok::animation::fermi_interpolator *this,
        char a2)
{
  vostok::animation::fermi_interpolator::~fermi_interpolator(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}

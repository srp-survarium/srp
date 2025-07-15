vostok::render::render_model_instance_impl *__thiscall vostok::render::render_model_instance_impl::`vector deleting destructor'(
        vostok::render::render_model_instance_impl *this,
        char a2)
{
  vostok::render::render_model_instance_impl::~render_model_instance_impl(this, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

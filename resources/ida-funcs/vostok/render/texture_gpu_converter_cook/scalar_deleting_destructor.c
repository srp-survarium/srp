vostok::render::texture_gpu_converter_cook *__thiscall vostok::render::texture_gpu_converter_cook::`scalar deleting destructor'(
        vostok::render::texture_gpu_converter_cook *this,
        char a2)
{
  vostok::render::texture_gpu_converter_cook::~texture_gpu_converter_cook(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

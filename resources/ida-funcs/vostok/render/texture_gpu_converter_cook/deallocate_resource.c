void __thiscall vostok::render::texture_gpu_converter_cook::deallocate_resource(
        vostok::render::texture_gpu_converter_cook *this,
        void **buffer)
{
  vostok::render::texture_compressor_deallocate(buffer[66]);
  vostok::render::texture_compressor_deallocate(buffer);
}

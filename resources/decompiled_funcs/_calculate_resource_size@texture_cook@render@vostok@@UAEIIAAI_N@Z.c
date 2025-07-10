unsigned int __thiscall vostok::render::texture_cook::calculate_resource_size(
        vostok::render::texture_cook *this,
        unsigned int file_size,
        unsigned int *out_offset_to_file,
        bool file_exist)
{
  *out_offset_to_file = 4;
  return file_size + 4;
}

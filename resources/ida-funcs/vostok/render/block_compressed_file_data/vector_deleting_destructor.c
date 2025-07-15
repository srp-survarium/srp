vostok::render::block_compressed_file_data *__thiscall vostok::render::block_compressed_file_data::`vector deleting destructor'(
        vostok::render::block_compressed_file_data *this,
        char a2)
{
  this->__vftable = (vostok::render::block_compressed_file_data_vtbl *)&vostok::render::block_compressed_file_data::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

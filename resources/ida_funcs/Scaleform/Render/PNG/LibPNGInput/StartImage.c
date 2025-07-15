bool __thiscall Scaleform::Render::PNG::LibPNGInput::StartImage(Scaleform::Render::PNG::LibPNGInput *this)
{
  bool result; // al
  png_struct_def *v3; // eax
  png_info_def *info_struct; // eax

  if ( this->IsInitialized )
    return 1;
  this->pFile.pObject->SeekToBegin(this->pFile.pObject);
  this->pFile.pObject->SkipBytes(this->pFile.pObject, 8);
  v3 = (png_struct_def *)png_create_read_struct("1.5.13", &this->Context, Scaleform::Render::PNG::png_error_handler, 0);
  this->Context.png_ptr = v3;
  if ( !v3 )
    return 0;
  info_struct = (png_info_def *)png_create_info_struct(v3);
  this->Context.info_ptr = info_struct;
  if ( info_struct )
  {
    png_set_read_fn(this->Context.png_ptr, this->pFile.pObject, Scaleform::Render::PNG::png_read_data);
    if ( Scaleform::Render::PNG::GFxPngReadInfo(&this->Context) )
    {
      result = 1;
      this->IsInitialized = 1;
    }
    else
    {
      png_destroy_read_struct(&this->Context, &this->Context.info_ptr, 0);
      return 0;
    }
  }
  else
  {
    png_destroy_read_struct(&this->Context, 0, 0);
    return 0;
  }
  return result;
}

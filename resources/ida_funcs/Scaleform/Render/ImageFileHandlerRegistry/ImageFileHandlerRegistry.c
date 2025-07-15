void Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        unsigned int handlerCount,
        ...)
{
  unsigned int v2; // eax
  Scaleform::Array<Scaleform::Render::ImageFileHandler *,2,Scaleform::ArrayDefaultPolicy> *p_Handlers; // edi
  unsigned int *p_handlerCount; // ebp
  unsigned int v5; // ebx
  unsigned int v6; // esi
  Scaleform::Render::ImageFileHandler **v7; // eax
  unsigned int v8; // [esp+0h] [ebp-4h]

  v2 = handlerCount;
  p_Handlers = &this->Handlers;
  this->__vftable = (Scaleform::Render::ImageFileHandlerRegistry_vtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable';
  this->Handlers.Data.Data = 0;
  this->Handlers.Data.Size = 0;
  this->Handlers.Data.Policy.Capacity = 0;
  if ( v2 )
  {
    p_handlerCount = &handlerCount;
    v8 = v2;
    do
    {
      v5 = p_handlerCount[1];
      ++p_handlerCount;
      if ( v5 )
      {
        v6 = this->Handlers.Data.Size + 1;
        if ( v6 >= this->Handlers.Data.Size )
        {
          if ( v6 >= this->Handlers.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)p_Handlers,
              p_Handlers,
              v6 + (v6 >> 2));
        }
        else if ( v6 < this->Handlers.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Handlers,
            &this->Handlers,
            this->Handlers.Data.Size + 1);
        }
        v7 = &p_Handlers->Data.Data[v6 - 1];
        this->Handlers.Data.Size = v6;
        if ( v7 )
          *v7 = (Scaleform::Render::ImageFileHandler *)v5;
      }
      --v8;
    }
    while ( v8 );
  }
}

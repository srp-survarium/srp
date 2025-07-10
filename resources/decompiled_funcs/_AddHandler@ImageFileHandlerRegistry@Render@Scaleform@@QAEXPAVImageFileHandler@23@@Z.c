void __thiscall Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileHandler *handler)
{
  int v4; // edi
  Scaleform::Render::ImageFileHandler *v5; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_Handlers; // edi
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **v8; // eax
  Scaleform::Render::ImageFileHandler *handlera; // [esp+Ch] [ebp+4h]

  if ( handler )
  {
    v4 = 0;
    if ( this->Handlers.Data.Size )
    {
      while ( 1 )
      {
        v5 = this->Handlers.Data.Data[v4];
        handlera = (Scaleform::Render::ImageFileHandler *)handler->GetFormat(handler);
        if ( (Scaleform::Render::ImageFileHandler *)v5->GetFormat(v5) == handlera )
          break;
        if ( ++v4 >= this->Handlers.Data.Size )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      p_Handlers = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Handlers;
      v7 = this->Handlers.Data.Size + 1;
      if ( v7 >= p_Handlers->Size )
      {
        if ( v7 >= p_Handlers->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Handlers,
            p_Handlers,
            v7 + (v7 >> 2));
      }
      else if ( v7 < p_Handlers->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Handlers,
          p_Handlers,
          v7);
      }
      v8 = &p_Handlers->Data[v7 - 1];
      p_Handlers->Size = v7;
      if ( v8 )
        *v8 = (Scaleform::GFx::AS3::Instances::fl::Object *)handler;
    }
  }
}

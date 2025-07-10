char __thiscall Scaleform::GFx::MovieImpl::RegisterFont(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieDef *md,
        Scaleform::GFx::FontResource *fontRes)
{
  unsigned int Size; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::MovieImpl::FontDesc *Data; // edx
  Scaleform::GFx::FontResource *v7; // ebp
  Scaleform::GFx::MovieDef *v9; // ebx
  unsigned int v10; // esi
  unsigned int v11; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_RegisteredFonts; // edi
  unsigned int v13; // esi
  unsigned int v14; // eax
  int v15; // ebx
  unsigned int v16; // ebp
  Scaleform::GFx::Resource *v17; // ecx
  Scaleform::GFx::Button::CharToRec *v18; // edx
  Scaleform::GFx::MovieDef **v19; // esi
  Scaleform::GFx::MovieImpl *v20; // [esp+Ch] [ebp-4h]

  Size = this->RegisteredFonts.Data.Size;
  v5 = 0;
  v20 = this;
  if ( Size )
  {
    Data = this->RegisteredFonts.Data.Data;
    while ( 1 )
    {
      v7 = fontRes;
      if ( Data->pFont.pObject == fontRes && Data->pMovieDef.pObject == md )
        return 0;
      ++v5;
      ++Data;
      if ( v5 >= Size )
        goto LABEL_9;
    }
  }
  else
  {
    v7 = fontRes;
LABEL_9:
    if ( v7 )
      Scaleform::RefCountImpl::AddRef(v7);
    v9 = md;
    if ( md )
      Scaleform::RefCountImpl::AddRef(md);
    v10 = this->RegisteredFonts.Data.Size;
    v11 = v10;
    p_RegisteredFonts = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&this->RegisteredFonts;
    v13 = v10 + 1;
    if ( v13 >= v11 )
    {
      if ( v13 >= p_RegisteredFonts->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_RegisteredFonts,
          p_RegisteredFonts,
          v13 + (v13 >> 2));
    }
    else
    {
      v14 = v11 - v13;
      v15 = (int)&p_RegisteredFonts->Data[v14 - 1 + v13];
      if ( v14 )
      {
        v16 = v14;
        do
        {
          v17 = *(Scaleform::GFx::Resource **)(v15 + 4);
          if ( v17 )
            Scaleform::GFx::Resource::Release(v17);
          if ( *(_DWORD *)v15 )
            Scaleform::GFx::Resource::Release(*(Scaleform::GFx::Resource **)v15);
          v15 -= 8;
          --v16;
        }
        while ( v16 );
        v7 = fontRes;
      }
      if ( v13 < p_RegisteredFonts->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_RegisteredFonts,
          p_RegisteredFonts,
          v13);
      v9 = md;
    }
    v18 = p_RegisteredFonts->Data;
    p_RegisteredFonts->Size = v13;
    v19 = (Scaleform::GFx::MovieDef **)&v18[v13 - 1];
    if ( v19 )
    {
      if ( v9 )
        Scaleform::RefCountImpl::AddRef(v9);
      *v19 = v9;
      if ( v7 )
        Scaleform::RefCountImpl::AddRef(v7);
      v19[1] = (Scaleform::GFx::MovieDef *)v7;
    }
    v20->Flags2 |= 2u;
    if ( v7 )
      Scaleform::GFx::Resource::Release(v7);
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    return 1;
  }
}

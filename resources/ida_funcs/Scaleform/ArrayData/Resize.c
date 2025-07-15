void __thiscall Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::DisplayList::DepthToIndexMapElem *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->Depth = -1;
          v5->Index = -1;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::TimelineDef::Frame *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->pTagPtrList = 0;
          v5->TagCount = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::TimelineDef::Frame *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->pTagPtrList = 0;
          v5->TagCount = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::Text::HighlightDesc>::ConstructArray(
      (char *)&this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v4; // eax
  int v5; // esi

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = &this->Data[Size];
    v5 = newSize - Size;
    if ( newSize != Size )
    {
      do
      {
        if ( v4 )
          v4->KeyCode = -1;
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // esi

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
      &this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // esi
  int v4; // edi
  Scaleform::Render::StrokeStyleType *v5; // eax

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->pFill.pObject = 0;
          v5->pDashes.pObject = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::AS2::Environment::TryDescr *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
          v5->TopStackIndex = 0;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::GFx::Text::CSSToken<wchar_t>>::ConstructArray(
      &this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // esi
  int v4; // edi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v5; // eax

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,Scaleform::AllocatorLH<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->info.Data.Data = 0;
          v5->info.Data.Size = 0;
          v5->info.Data.Policy.Capacity = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->GlyphAdvance = 0.0;
          v5->GlyphIndex = -1;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::Waitable::HandlerStruct *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->Handler = 0;
          v5->pUserData = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Abc::NamespaceInfo>::ConstructArray(
      &this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::GFx::AS3::Abc::StringView *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
          v5->Data = &Scaleform::GFx::AS3::Abc::StringView::Empty;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::Matrix2x4<float>>::ConstructArray(
      (char *)&this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::Matrix3x4<float>>::ConstructArray(
      (float *)&this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
    Scaleform::ConstructorMov<Scaleform::Render::Matrix4x4<float>>::ConstructArray(
      (float *)&this->Data[Size],
      newSize - Size);
}


void __thiscall Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // ebx
  int v4; // esi
  Scaleform::RangeData<void *> *v5; // eax

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        newSize + (newSize >> 2));
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      newSize);
  }
  this->Size = newSize;
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->Index = 0;
          v5->Length = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}

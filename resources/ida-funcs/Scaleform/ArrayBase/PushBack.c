void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const unsigned __int8 *val)
{
  unsigned int v3; // esi
  unsigned __int8 *Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (unsigned __int8 *)1 )
    Data[v3 - 1] = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const unsigned __int8 *val)
{
  unsigned int v3; // edi
  unsigned __int8 *Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  Data[v3 - 1] = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const int *val)
{
  unsigned int v3; // esi
  int *Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (int *)4 )
    Data[v3 - 1] = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::GFx::AS2::Value *const *val)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS2::Value **Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (Scaleform::GFx::AS2::Value **)4 )
    Data[v3 - 1] = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    this->Data.Size + 1);
  if ( &this->Data.Data[this->Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
    Scaleform::GFx::AS2::Value::Value(&this->Data.Data[this->Data.Size - 1], val);
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::Render::Point<long> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Point<long> *Data; // edx
  Scaleform::Render::Point<long> *v5; // eax
  int y; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  v5 = &Data[v3 - 1];
  if ( &Data[v3] != (Scaleform::Render::Point<long> *)8 )
  {
    y = val->y;
    v5->x = val->x;
    v5->y = y;
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::GFx::ASString *val)
{
  Scaleform::GFx::ASStringNode *pNode; // eax

  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    this->Data.Size + 1);
  if ( &this->Data.Data[this->Data.Size] != (Scaleform::GFx::ASString *)4 )
  {
    pNode = val->pNode;
    this->Data.Data[this->Data.Size - 1] = (Scaleform::GFx::ASString)val->pNode;
    ++pNode->RefCount;
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int8 *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned __int8 *Data; // eax
  unsigned __int8 *v6; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy> > *this,
        const unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned int *Data; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  Data[v4 - 1] = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<long,Scaleform::AllocatorDH<long,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned int *Data; // eax
  unsigned int *v6; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const long double *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  long double *Data; // eax
  double *v6; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *(double *)val;
}

void __thiscall Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *this,
        const unsigned __int8 *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 12;
  if ( v3 >= this->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this,
      this->Size >> 12);
  this->Pages[v3][this->Size++ & 0xFFF] = *val;
}


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this,
        const Scaleform::GFx::AS3::CallFrame *val)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::CallFrame *v4; // ecx

  v3 = this->Size >> 6;
  if ( v3 >= this->NumPages )
    Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
      this,
      this->Size >> 6);
  v4 = &this->Pages[v3][this->Size & 0x3F];
  if ( v4 )
    Scaleform::GFx::AS3::CallFrame::CallFrame(v4, val);
  ++this->Size;
}

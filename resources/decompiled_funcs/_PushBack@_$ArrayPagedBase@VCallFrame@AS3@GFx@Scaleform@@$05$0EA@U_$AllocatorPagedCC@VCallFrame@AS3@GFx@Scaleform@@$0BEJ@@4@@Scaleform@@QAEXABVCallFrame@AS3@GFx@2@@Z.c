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

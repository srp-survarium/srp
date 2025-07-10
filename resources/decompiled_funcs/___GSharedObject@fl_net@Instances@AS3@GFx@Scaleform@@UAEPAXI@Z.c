Scaleform::GFx::AS3::Instances::fl_net::SharedObject *__thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject::~SharedObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

void __thiscall Scaleform::GFx::AS3::ReadArgsMnObjectRef::~ReadArgsMnObjectRef(
        Scaleform::GFx::AS3::ReadArgsMnObjectRef *this)
{
  Scaleform::GFx::AS3::Multiname::~Multiname(&this->ArgMN);
  Scaleform::GFx::AS3::ReadArgs::~ReadArgs(this);
}

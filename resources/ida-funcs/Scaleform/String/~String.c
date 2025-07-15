void __thiscall Scaleform::String::~String(Scaleform::String *this)
{
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(this->HeapTypeBits & 0xFFFFFFFC));
}

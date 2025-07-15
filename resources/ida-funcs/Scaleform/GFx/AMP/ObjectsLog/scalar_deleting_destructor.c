Scaleform::GFx::AMP::ObjectsLog *__thiscall Scaleform::GFx::AMP::ObjectsLog::`scalar deleting destructor'(
        Scaleform::GFx::AMP::ObjectsLog *this,
        char a2)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&this->Report);
  Scaleform::Log::~Log(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

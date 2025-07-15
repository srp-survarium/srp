BOOL __thiscall Scaleform::Range::Intersects(Scaleform::Range *this, const Scaleform::Range *r)
{
  return (signed int)(r->Length + r->Index - 1) >= this->Index
      && (signed int)(this->Length + this->Index - 1) >= r->Index;
}

btDbvtBroadphase *__thiscall btDbvtBroadphase::`scalar deleting destructor'(btDbvtBroadphase *this, char a2)
{
  btDbvtBroadphase::~btDbvtBroadphase(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

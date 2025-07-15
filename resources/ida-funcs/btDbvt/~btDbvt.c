void __thiscall btDbvt::~btDbvt(btDbvt *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx

  btDbvt::clear(this, this);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v2, (int)&this->m_stkStack);
}

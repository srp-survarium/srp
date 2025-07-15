void __usercall Wm4::Box2<float>::Box2<float>(Wm4::Box2<float> *this@<esi>, const Wm4::Box2<float> *__that@<edi>)
{
  this->Center.m_afTuple[0] = __that->Center.m_afTuple[0];
  this->Center.m_afTuple[1] = __that->Center.m_afTuple[1];
  `vector copy constructor iterator'(
    (char *)this->Axis,
    (char *)__that->Axis,
    8u,
    2,
    (void *(__thiscall *)(void *, void *))Wm4::Vector2<float>::Vector2<float>);
  *(_QWORD *)this->Extent = *(_QWORD *)__that->Extent;
}

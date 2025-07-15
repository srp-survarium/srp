const btTransform *__thiscall btSoftBody::Body::xform(btSoftBody::Body *this, _DWORD *a2)
{
  int v2; // eax

  if ( (`btSoftBody::Body::xform'::`2'::`local static guard' & 1) == 0 )
  {
    `btSoftBody::Body::xform'::`2'::`local static guard' |= 1u;
    `btSoftBody::Body::xform'::`2'::identity = *btTransform::getIdentity();
  }
  v2 = a2[2];
  if ( v2 )
    return (const btTransform *)(v2 + 16);
  if ( *a2 )
    return (const btTransform *)(*a2 + 64);
  return &`btSoftBody::Body::xform'::`2'::identity;
}

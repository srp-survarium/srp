void __usercall safe_release<ID3D11Buffer>(IUnknown **object@<esi>)
{
  if ( *object )
  {
    (*object)->Release(*object);
    *object = 0;
  }
}

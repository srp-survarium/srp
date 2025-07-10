void __usercall stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        D3D11_INPUT_ELEMENT_DESC *__first@<ecx>,
        D3D11_INPUT_ELEMENT_DESC *__last@<eax>,
        const D3D11_INPUT_ELEMENT_DESC *__val@<esi>)
{
  int i; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    *__first = *__val;
    --i;
  }
}

D3D11_INPUT_ELEMENT_DESC *__fastcall stlp_std::priv::__fill_n<vostok::render::ui::vertex *,unsigned int,vostok::render::ui::vertex>(
        const D3D11_INPUT_ELEMENT_DESC *__val,
        unsigned int __n,
        D3D11_INPUT_ELEMENT_DESC *__first)
{
  D3D11_INPUT_ELEMENT_DESC *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}

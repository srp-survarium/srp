// attributes: thunk
HRESULT __stdcall DirectInput8Create(
        HINSTANCE hinst,
        DWORD dwVersion,
        const IID *const riidltf,
        LPVOID *ppvOut,
        LPUNKNOWN punkOuter)
{
  return __imp__DirectInput8Create@20(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}

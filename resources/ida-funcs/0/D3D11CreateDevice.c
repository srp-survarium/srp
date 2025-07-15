// attributes: thunk
HRESULT __stdcall D3D11CreateDevice(
        IDXGIAdapter *pAdapter,
        D3D_DRIVER_TYPE DriverType,
        HMODULE Software,
        UINT Flags,
        const D3D_FEATURE_LEVEL *pFeatureLevels,
        UINT FeatureLevels,
        UINT SDKVersion,
        ID3D11Device **ppDevice,
        D3D_FEATURE_LEVEL *pFeatureLevel,
        ID3D11DeviceContext **ppImmediateContext)
{
  return __imp__D3D11CreateDevice@40(
           pAdapter,
           DriverType,
           Software,
           Flags,
           pFeatureLevels,
           FeatureLevels,
           SDKVersion,
           ppDevice,
           pFeatureLevel,
           ppImmediateContext);
}

int __cdecl Scaleform::Thread::GetOSPriority(Scaleform::Thread::ThreadPriority p)
{
  int result; // eax

  switch ( p )
  {
    case CriticalPriority:
      result = 15;
      break;
    case HighestPriority:
      result = 2;
      break;
    case AboveNormalPriority:
      result = 1;
      break;
    case BelowNormalPriority:
      result = -1;
      break;
    case LowestPriority:
      result = -2;
      break;
    case IdlePriority:
      result = -15;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

#include "kernel.h"
#include "keyboard.h"

static uint8_t btKeyboardLayoutUS[] = {
  0, 0, 0,
  0x1B, 0x1B, 0x1B,	/*      esc     (0x01)  */
  '1', '!', '1',
  '2', '@', '2',
  '3', '#', '3',
  '4', '$', '4',
  '5', '%', '5',
  '6', '^', '6',
  '7', '&', '7',
  '8', '*', '8',
  '9', '(', '9',
  '0', ')', '0',
  '-', '_', '-',
  '=', '+', '=',
  0x08, 0x08, 0x7F,	/*      backspace       */
  0x09, 0x09, 0x09,	/*      tab     */
  'q', 'Q', 'q',
  'w', 'W', 'w',
  'e', 'E', 'e',
  'r', 'R', 'r',
  't', 'T', 't',
  'y', 'Y', 'y',
  'u', 'U', 'u',
  'i', 'I', 'i',
  'o', 'O', 'o',
  'p', 'P', 'p',
  '[', '{', '[',
  ']', '}', ']',
  0x0A, 0x0A, 0x0A,	/*      enter   */
  0xFF, 0xFF, 0xFF,	/*      ctrl    */
  'a', 'A', 'a',
  's', 'S', 's',
  'd', 'D', 'd',
  'f', 'F', 'f',
  'g', 'G', 'g',
  'h', 'H', 'h',
  'j', 'J', 'j',
  'k', 'K', 'k',
  'l', 'L', 'l',
  ';', ':', ';',
  0x27, 0x22, 0x27,	/*      '"      */
  '`', '~', '`',	/*      `~      */
  0xFF, 0xFF, 0xFF,	/*      Lshift  (0x2a)  */
  '\\', '|', '\\',
  'z', 'Z', 'z',
  'x', 'X', 'x',
  'c', 'C', 'c',
  'v', 'V', 'v',
  'b', 'B', 'b',
  'n', 'N', 'n',
  'm', 'M', 'm',
  0x2C, 0x3C, 0x2C,	/*      ,<      */
  0x2E, 0x3E, 0x2E,	/*      .>      */
  0x2F, 0x3F, 0x2F,	/*      /?      */
  0xFF, 0xFF, 0xFF,	/*      Rshift  (0x36)  */
  0xFF, 0xFF, 0xFF,	/*      (0x37)  */
  0xFF, 0xFF, 0xFF,	/*      (0x38)  */
  ' ', ' ', ' ',	/*      space   */
  0xFF, 0xFF, 0xFF,	/*      (0x3a)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3b)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3c)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3d)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3e)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3f)  */
  0xFF, 0xFF, 0xFF,	/*      (0x40)  */
  0xFF, 0xFF, 0xFF,	/*      (0x41)  */
  0xFF, 0xFF, 0xFF,	/*      (0x42)  */
  0xFF, 0xFF, 0xFF,	/*      (0x43)  */
  0xFF, 0xFF, 0xFF,	/*      (0x44)  */
  0xFF, 0xFF, 0xFF,	/*      (0x45)  */
  0xFF, 0xFF, 0xFF,	/*      (0x46)  */
  0xFF, 0xFF, 0xFF,	/*      (0x47)  */
  0xFF, 0xFF, 0xFF,	/*      (0x48)  */
  0xFF, 0xFF, 0xFF,	/*      (0x49)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4a)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4b)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4c)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4d)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4e)  */
  0xFF, 0xFF, 0xFF,	/*      (0x4f)  */
  0xFF, 0xFF, 0xFF,	/*      (0x50)  */
  0xFF, 0xFF, 0xFF,	/*      (0x51)  */
  0xFF, 0xFF, 0xFF,	/*      (0x52)  */
  0xFF, 0xFF, 0xFF,	/*      (0x53)  */
  0xFF, 0xFF, 0xFF,	/*      (0x54)  */
  0xFF, 0xFF, 0xFF,	/*      (0x55)  */
  0xFF, 0xFF, 0xFF,	/*      (0x56)  */
  0xFF, 0xFF, 0xFF,	/*      (0x57)  */
  0xFF, 0xFF, 0xFF,	/*      (0x58)  */
  0xFF, 0xFF, 0xFF,	/*      (0x59)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5a)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5b)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5c)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5d)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5e)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5f)  */
  0xFF, 0xFF, 0xFF,	/*      (0x60)  */
  0xFF, 0xFF, 0xFF,	/*      (0x61)  */
};

static uint8_t btKeyboardLayoutFR[] = {
  0, 0, 0,
  VK_ESCAPE, VK_ESCAPE, VK_ESCAPE,	/*      esc     (0x01)  */
  '&', '1', 0,
  0x82, '2', '~',
  '"', '3', '#',
  '\'', '4', '{',
  '(', '5', '[',
  '-', '6', '|',
  0x8A, '7', '`',
  '_', '8', '\\',
  0x87, '9', '^',
  0x85, '0', '@',
  ')', 0xF8, ']',
  '=', '+', '}',
  VK_BACKSPACE, VK_BACKSPACE, VK_BACKSPACE,	/*      backspace       */
  VK_TAB, VK_TAB, VK_TAB,	/*      tab     */
  'a', 'A', 0,
  'z', 'Z', 0,
  'e', 'E', 0,
  'r', 'R', 0,
  't', 'T', 0,
  'y', 'Y', 0,
  'u', 'U', 0,
  'i', 'I', 0,
  'o', 'O', 0,
  'p', 'P', 0,
  '^', '{', 0,
  '$', 0x9C, 0,
  VK_RETURN, VK_RETURN, VK_RETURN,	/*      enter   */
  0xFF, 0xFF, 0xFF,	/*      ctrl    */
  'q', 'Q', 0,
  's', 'S', 0,
  'd', 'D', 0,
  'f', 'F', 0,
  'g', 'G', 0,
  'h', 'H', 0,
  'j', 'J', 0,
  'k', 'K', 0,
  'l', 'L', 0,
  'm', 'M', 0,
  0x97, 0x25, 0,	/*      ù %      */
  0xFD, 0xFF, 0,	/* ² */
  0xFF, 0xFF, 0xFF,	/*      Lshift  (0x2a)  */
  0x2A, 0xE6, 0,       	/*      * µ      */
  'w', 'W', 0,
  'x', 'X', 0,
  'c', 'C', 0,
  'v', 'V', 0,
  'b', 'B', 0,
  'n', 'N', 0,
  ',', '?', 0,
  ';', '.', 0,	/*      ù %      */
  ':', '/', 0,		/*      .>      */
  '!', 0, 0,	/*      /?      */
  0xFF, 0xFF, 0xFF,	/*      Rshift  (0x36)  */
  '*', 0, 0,		/*      (0x37)  */
  0xFF, 0xFF, 0xFF,	/*      (0x38)  */
  ' ', ' ', ' ',	/*      space   */
  0xFF, 0xFF, 0xFF,	/*      (0x3a)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3b)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3c)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3d)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3e)  */
  0xFF, 0xFF, 0xFF,	/*      (0x3f)  */
  0xFF, 0xFF, 0xFF,	/*      (0x40)  */
  0xFF, 0xFF, 0xFF,	/*      (0x41)  */
  0xFF, 0xFF, 0xFF,	/*      (0x42)  */
  0xFF, 0xFF, 0xFF,	/*      (0x43)  */
  0xFF, 0xFF, 0xFF,	/*      (0x44)  */
  0xFF, 0xFF, 0xFF,	/*      (0x45)  */
  0xFF, 0xFF, 0xFF,	/*      (0x46)  */
  '7', 0, 0,		/*      (0x47)  */
  '8', 0, 0,		/*      (0x48)  */
  '9', 0, 0,		/*      (0x49)  */
  '-', 0, 0,		/*      (0x4a)  */
  '4', 0, 0,		/*      (0x4b)  */
  '5', 0, 0,		/*      (0x4c)  */
  '6', 0, 0,		/*      (0x4d)  */
  '+', 0, 0,		/*      (0x4e)  */
  '1', 0, 0,		/*      (0x4f)  */
  '2', 0, 0,		/*      (0x50)  */
  '3', 0, 0,		/*      (0x51)  */
  '0', 0, 0,		/*      (0x52)  */
  '.', 0, 0,		/*      (0x53)  */
  0xFF, 0xFF, 0xFF,	/*      (0x54)  */
  0xFF, 0xFF, 0xFF,	/*      (0x55)  */
  '<', '>', 0,		/*      (0x56)  */
  0xFF, 0xFF, 0xFF,	/*      (0x57)  */
  0xFF, 0xFF, 0xFF,	/*      (0x58)  */
  0xFF, 0xFF, 0xFF,	/*      (0x59)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5a)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5b)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5c)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5d)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5e)  */
  0xFF, 0xFF, 0xFF,	/*      (0x5f)  */
  0xFF, 0xFF, 0xFF,	/*      (0x60)  */
  0xFF, 0xFF, 0xFF,	/*      (0x61)  */
};

static uint8_t *ppKeyboardLayout[] = {
  btKeyboardLayoutUS,
  btKeyboardLayoutFR
};

uint32_t GetVirtualKey(void)
{
  static uint32_t dwFlags;
  static bool bEscaped;
  uint32_t vk = 0;
  uint8_t sc, c;

  sc = GetScanCode();

  if (sc == 0xE0)
    {
      bEscaped = TRUE;
      return 0;
    }

  c = sc;
  if (c & VK_KEYUP) // key up
    c -= VK_KEYUP;

  switch (c)
    {
    case 0x36:
      dwFlags ^= VK_RSHIFT;
      break;

    case 0x2A:
      dwFlags ^= VK_LSHIFT;
      break;

    case 0x1D:
      dwFlags ^= (bEscaped ? VK_RCONTROL : VK_LCONTROL);
      break;

    case 0x38:
      dwFlags ^= (bEscaped ? VK_RMENU : VK_LMENU);
      break;

    case 0x4D:
      vk = dwFlags | (bEscaped ? VK_RIGHT : sc);
      break;

    case 0x4B:
      vk = dwFlags | (bEscaped ? VK_LEFT : sc);
      break;

    default:
      vk = dwFlags | sc;
    }

  bEscaped = FALSE;
  return vk;
}


static uint32_t	VirtualKeyToScanCode(uint32_t vk, uint32_t dwKeyboardLayout)
{
  uint8_t c, s;

  s = 0;
  c = vk & 0x7F;

  if (vk & VK_SHIFT)
    s++;
  else if (vk & VK_RMENU)
    s += 2;

  return ppKeyboardLayout[dwKeyboardLayout][c * 3 + s];
}

static uint32_t ScanCodeToVirtualKey(uint32_t uCode, uint32_t dwKeyboardLayout)
{
  UNUSED(uCode);
  UNUSED(dwKeyboardLayout);
  return 0;
}

uint32_t	MapVirtualKey(uint32_t uCode, uint32_t uMapType, uint32_t dwKeyboardLayout)
{
  switch (uMapType)
    {
    case MAPVK_VK_TO_VSC:
      return VirtualKeyToScanCode(uCode, dwKeyboardLayout);

    case MAPVK_VSC_TO_VK:
      return ScanCodeToVirtualKey(uCode, dwKeyboardLayout);
    }
  return 0;
}

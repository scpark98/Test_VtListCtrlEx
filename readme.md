[수정된 내용]
*20250818
- CPathCtrl, CSCTreeCtrl, CVtListCtrlEx에서 set_path(_T("c:\\")) 와 같이 설정할 경우
  대소문자로 인해 해당 경로가 제대로 선택되지 않던 오류 수정.
- CSCTreeCtrl에서 "내 PC\\연구소문서2(\\\\192.168.1.103) (X:)" 와 같은 경로가 정확히 2개의 토큰으로 분리되지 않던 오류 수정.
  (get_exact_token_string() 함수 추가)
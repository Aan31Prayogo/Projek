import cv2

cap=cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)
url=

while True:
    _,frame= cap.read()
    cv2.imshow("frame",frame)
    q=cv2.waitKey(1)

    if q == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()


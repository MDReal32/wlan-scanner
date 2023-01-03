// @ts-ignore
import { getAccessPointList } from "../../build/Release/wlan_scanner.node";
import { WlanAccessPoint } from "../types";

export const getAccessPoints = (): WlanAccessPoint[] => {
  return JSON.parse(getAccessPointList());
};
